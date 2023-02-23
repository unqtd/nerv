#include "../util.h"
#include <stdint.h>

#ifndef _ATTINY_2313_H
#define _ATTINY_2313_H

#if defined(__AVR_ATtiny2313A__) || defined(__AVR_ATtiny2313__)

///////////////////////////////////////////////////////////
// Common

inline port_t const *_get_port(const uint8_t pin) {
  static port_t const portb = {&DDRB, &PORTB, &PINB};
  static port_t const porta = {&DDRA, &PORTA, &PINA};
  static port_t const portd = {&DDRD, &PORTD, &PIND};

  if (pin <= 1 || (pin > 3 && pin <= 8))
    return &portd;
  else if (pin <= 3 || pin == 17)
    return &porta;
  else if (pin <= 16)
    return &portb;
  else
    return NULL;
}

inline uint8_t _get_port_pin(const uint8_t pin) {
  static uint8_t const PINS[] = {PD0, PD1, PA1, PA0, PD2, PD3, PD4, PD5, PD6,
                                 PB0, PB1, PB2, PB3, PB4, PB5, PB7, PA2};
  return PINS[pin];
}

///////////////////////////////////////////////////////////
/// Analog

inline void _init_fast_pwm(const uint8_t timer) {
  switch (timer) {
  case 0:
    TCCR0A |= bit(WGM01) | bit(WGM00);
    TCCR0B |= bit(CS01);
    break;
  case 1:
    TCCR1A |= bit(WGM10);
    TCCR1B |= bit(WGM12) | bit(CS11);
    break;
  }
}

inline void _init_pwm_pin(const uint8_t pin) {
  switch (pin) {
  case 7:
    TCCR0A |= bit(COM0B1);
    break;
  case 11:
    TCCR0A |= bit(COM0A1);
    break;
  case 13:
    TCCR1A |= bit(COM1B1);
    break;
  case 12:
    TCCR1A |= bit(COM1A1);
    break;
  }
}

inline void _set_pwm_on_pin(const uint8_t pin, const uint16_t value) {
  switch (pin) {
  case 7:
    OCR0B = value;
    break;
  case 11:
    OCR0A = value;
    break;
  case 13:
    OCR1B = value;
    break;
  case 12:
    OCR1A = value;
    break;
  }
}

inline void _turn_of_pwm(const uint8_t timer) {
  switch (timer) {
  case 0:
    TCCR0B &= ~(bit(CS02) | bit(CS01) | bit(CS00));
    break;
  case 1:
    TCCR1B &= ~(bit(CS12) | bit(CS11) | bit(CS10));
    break;
  }
}

///////////////////////////////////////////////////////////
// Timers

inline uint8_t _get_timer(const uint8_t pin) {
  if (pin == 12 || pin == 13)
    return 1;
  else
    return 0;
}

///////////////////////////////////////////////////////////
// ADC

inline uint16_t _adc_read() { return 0; }

#endif // !__AVR_ATtiny2313A__
#endif // !_2313_H
