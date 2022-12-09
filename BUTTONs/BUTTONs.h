#ifndef BUTTONs_h
#define BUTTONs_h
#include "Arduino.h"


class BUTTONs {
public:
  BUTTONs(int pin, unsigned long debDelay,unsigned long longPressDelay,bool pullUp);  //CONSTRUCTOR (button pin, needed time delay to debounce the button in milliseconds (suggested >80),set the duration of a long press of a button in milliseconds, 1 to toggle PULLUP resistor 0 otherwise)
  bool isPressed();                                                            // Returns 1 if the button is pressed shortly (already debounced)
  bool isLongPressed();                                                        // Returns 1 if a long press of the specified duration occured
private:
  unsigned long _firstPress;
  unsigned long _debDelay;
  unsigned long _longPressDelay;
  bool _inputState;
  bool _pullUp;
  int _pin;
};

#endif