#include "../util.h"
#include <stdint.h>

#ifndef _NERV_ATTINY13_H
#define _NERV_ATTINY13_H

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__)

///////////////////////////////////////////////////////////
// Common

inline port_t const *_get_port(pin_t pin) {
  static port_t const portb = {&DDRB, &PORTB, &PINB};

  if (pin >= 0 && pin <= 5)
    return &portb;
  else
    return NULL;
}

inline uint8_t _get_port_pin(pin_t pin) {
  static uint8_t const PINS[] = {PB0, PB1, PB2, PB3, PB4, PB5};
  return PINS[pin];
}

///////////////////////////////////////////////////////////
// PWM

inline void _init_fast_pwm_prescaler(const uint8_t timer) {
  if (timer == 0) {
    TCCR0B |= bit(CS01);
  }
}

inline void _init_fast_pwm(const uint8_t timer) {
  if (timer == 0) {
    TCCR0A |= bit(WGM01) | bit(WGM00);
    _init_fast_pwm_prescaler(timer);
  }
}

inline void _init_pwm_pin(const uint8_t pin) {
  switch (pin) {
  case 1:
    TCCR0A |= bit(COM0B1);
    break;
  case 0:
    TCCR0A |= bit(COM0A1);
    break;
  }
}

inline void _set_pwm_on_pin(pin_t pin, const uint16_t value) {
  switch (pin) {
  case 1:
    OCR0B = value;
    break;
  case 0:
    OCR0A = value;
    break;
  }
}

inline void _turn_of_pwm(const uint8_t timer) {
  if (timer == 0) {
    TCCR0B &= ~(bit(CS02) | bit(CS01) | bit(CS00));
  }
}

///////////////////////////////////////////////////////////
// Timers

inline uint8_t _get_timer(const uint8_t pin) { return 0; }

///////////////////////////////////////////////////////////
// ADC

inline void _adc_start() {
  // ...
  ADCSRA = _BV(ADEN) | _BV(ADSC);
}

inline void _adc_stop() {
  // ....
  ADCSRA = 0;
}

inline void _init_adc_pin(pin_t pin) {
  // ...
  ADMUX = (ADMUX & 0xFC) | pin;
}

inline uint16_t _adc_read(const uint8_t pin) {
  while (ADCSRA & bit(ADSC))
    ;
  return ADCW;
}

#endif
#endif /* !_NERV_ATTINY13_H */
