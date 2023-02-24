#include "nerv.h"

#ifndef _NERV_ANALOG_H
#define _NERV_ANALOG_H

inline void analog_write(pin_t pin, const uint8_t value) {
  const uint8_t timer = _get_timer(pin);

  if (value == 0) {
#ifndef ANALOG_WRITE_WITHOUT_ZERO
    _turn_of_pwm(timer);
    digital_write(pin, LOW);
#endif
  }
#ifdef ANALOG_WRITE_255
  else if (value == 255) {
    _turn_of_pwm(timer);
    digital_write(pin, HIGH);
  }
#endif
  else {
    _init_fast_pwm_prescaler(timer);
    _set_pwm_on_pin(pin, value);
  }
}

#define WITH_ADC(BLOCK)                                                        \
  {                                                                            \
    _adc_start();                                                              \
    BLOCK                                                                      \
    _adc_stop();                                                               \
  }

inline uint16_t analog_read(pin_t pin) {
  // ...
  return _adc_read(pin);
}

#endif
