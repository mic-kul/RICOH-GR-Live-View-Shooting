#include "ble_pairing_policy.h"

namespace {

// Mirrors the NimBLE constants without pulling its headers into native builds.
constexpr uint8_t kAddrPublic = 0x00;
constexpr uint8_t kAddrRandom = 0x01;
constexpr uint8_t kAddrPublicId = 0x02;
constexpr uint8_t kAddrRandomId = 0x03;

constexpr int kAttErrBase = 0x100;  // BLE_HS_ERR_ATT_BASE
constexpr int kAttInsufficientAuthen = kAttErrBase + 0x05;
constexpr int kAttInsufficientAuthor = kAttErrBase + 0x08;
constexpr int kAttInsufficientEnc = kAttErrBase + 0x0F;

// Camera unpaired on its side: encryption restore fails with 0x213 each try.
constexpr int kBondedSecurityFailureLimit = 3;
// Just Works bond: reads rejected despite an encrypted link.
constexpr int kInsufficientAuthReadLimit = 2;

}  // namespace

uint8_t normalizedPeerAddressType(uint8_t type) {
  if (type == kAddrPublicId) {
    return kAddrPublic;
  }
  if (type == kAddrRandomId) {
    return kAddrRandom;
  }
  return type;
}

bool attErrorMeansInsufficientAuth(int rc) {
  return rc == kAttInsufficientAuthen ||
         rc == kAttInsufficientAuthor ||
         rc == kAttInsufficientEnc;
}

bool PairingRecoveryPolicy::onBondedSecurityFailure() {
  if (++_securityFailures < kBondedSecurityFailureLimit) {
    return false;
  }
  _securityFailures = 0;
  return true;
}

bool PairingRecoveryPolicy::onInsufficientAuthRead() {
  if (++_rejectedReads < kInsufficientAuthReadLimit) {
    return false;
  }
  _rejectedReads = 0;
  return true;
}

void PairingRecoveryPolicy::onPairingSuccess() {
  _securityFailures = 0;
}

void PairingRecoveryPolicy::onAuthenticatedRead() {
  _rejectedReads = 0;
}

int32_t PasskeyDigitCollector::feed(char c) {
  if (c < '0' || c > '9') {
    return -1;
  }
  _value = _value * 10 + (c - '0');
  if (++_count < 6) {
    return -1;
  }
  const int32_t code = _value;
  _value = 0;
  _count = 0;
  return code;
}

void PasskeyButtonEntry::reset() {
  for (uint8_t i = 0; i < 6; i++) {
    _digits[i] = 0;
  }
  _index = 0;
}

void PasskeyButtonEntry::shortPress() {
  if (_index < 6) {
    _digits[_index] = static_cast<uint8_t>((_digits[_index] + 1) % 10);
  }
}

bool PasskeyButtonEntry::hold() {
  if (_index < 6) {
    _index++;
  }
  return _index >= 6;
}

int32_t PasskeyButtonEntry::code() const {
  int32_t code = 0;
  for (uint8_t i = 0; i < 6; i++) {
    code = code * 10 + _digits[i];
  }
  return code;
}
