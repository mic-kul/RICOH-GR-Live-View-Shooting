#pragma once

#include <cstdint>

// Host-testable pairing/recovery decision logic shared with ricoh_ble_client.
// GR III pairing background: the camera pairs via SMP Passkey Entry (camera
// displays a 6-digit code, this side submits it) and rejects protected reads
// on bonds that lack MITM authentication.

// Resolved identity address types map to their plain forms: pre-bond there is
// no IRK, and the GR III terminates pairing initiated against a PUBLIC_ID peer
// where the same request against PUBLIC succeeds.
uint8_t normalizedPeerAddressType(uint8_t type);

// ATT errors the camera returns when a bond lacks authentication.
bool attErrorMeansInsufficientAuth(int rc);

// Tracks the two bad-bond failure modes and decides when the stored bond must
// be dropped so the flow falls back to fresh passkey pairing:
// - camera unpaired on its side: encryption restore keeps failing (0x213)
// - Just Works bond: link encrypts but protected reads are rejected
class PairingRecoveryPolicy {
public:
  // Returns true when the bond should be dropped now; the counter resets.
  bool onBondedSecurityFailure();
  bool onInsufficientAuthRead();

  void onPairingSuccess();
  void onAuthenticatedRead();

private:
  int _securityFailures = 0;
  int _rejectedReads = 0;
};

// Collects passkey digits typed into the serial console. Non-digits are
// ignored; the 6-digit code is returned once complete, -1 until then.
class PasskeyDigitCollector {
public:
  int32_t feed(char c);

private:
  int32_t _value = 0;
  uint8_t _count = 0;
};

// Single-button passkey entry: a short press cycles the active digit 0-9, a
// hold confirms it and advances. hold() returns true once all six digits are
// confirmed; code() then yields the value to inject.
class PasskeyButtonEntry {
public:
  void reset();
  void shortPress();
  bool hold();
  int32_t code() const;
  uint8_t activeIndex() const { return _index; }
  const uint8_t* digits() const { return _digits; }

private:
  uint8_t _digits[6] = {0, 0, 0, 0, 0, 0};
  uint8_t _index = 0;
};
