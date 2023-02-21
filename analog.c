#include "nerv.h"

#ifndef _NERV_ANALOG_H
#define _NERV_ANALOG_H

inline void analog_write(pin_t pin, const uint8_t value) {
  if (value == 0)
    digital_write(pin, LOW);
  else if (value == 255)
    digital_write(pin, HIGH);

  _set_pwm_on_pin(pin, value);
}

#endif
