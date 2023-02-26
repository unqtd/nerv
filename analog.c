#include "nerv.h"

#ifndef _NERV_ANALOG_H
#define _NERV_ANALOG_H

inline void analog_write(pin_t pin, const uint16_t value) {
  _set_pwm_on_pin(pin, value);
}

inline uint16_t analog_read(adc_t adc, pin_t pin) {
  return _adc_read(adc, pin);
}

#endif
