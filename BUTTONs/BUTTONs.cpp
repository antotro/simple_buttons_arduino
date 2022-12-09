#include "BUTTONs.h"

BUTTONs::BUTTONs(int pin, unsigned long debDelay, unsigned long longPressDelay, bool pullUp) {
  _pin = pin;
  _debDelay = debDelay;
  _longPressDelay = longPressDelay;
  _pullUp = pullUp;
  if (!_pullUp) {
    pinMode(_pin, INPUT);
  } else if (_pullUp) {
    pinMode(_pin, INPUT_PULLUP);
  }
}

bool BUTTONs::isPressed() {
  if (!_pullUp) {
    if (digitalRead(_pin) && !_inputState) {
      _inputState = true;
      _firstPress = millis();
    }
    if (millis() - _firstPress > _debDelay && _inputState && !digitalRead(_pin)) {
      _inputState = false;
      if (millis() - _firstPress > _longPressDelay) {
        return false;
      }
      return true;
    } else return false;
  } else if (_pullUp) {
    if (!digitalRead(_pin) && !_inputState) {
      _inputState = true;
      _firstPress = millis();
    }
    if (millis() - _firstPress > _debDelay && _inputState && digitalRead(_pin)) {
      _inputState = false;
      if (millis() - _firstPress > _longPressDelay) {
        return false;
      }
      return true;
    } else return false;
  }
}

bool BUTTONs::isLongPressed() {
  if (!_pullUp) {
    if (digitalRead(_pin) && !_inputState) {
      _firstPress = millis();
      _inputState = true;
    }
    if (millis() - _firstPress >= _longPressDelay && _inputState && digitalRead(_pin)) {
      return true;
    } else return false;
  }
  if (_pullUp) {
    if (!digitalRead(_pin) && !_inputState) {
      _firstPress = millis();
      _inputState = true;
    }
    if (millis() - _firstPress >= _longPressDelay && _inputState && !digitalRead(_pin)) {
      return true;
    } else return false;
  }
}