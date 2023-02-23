#include <avr/io.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _NERV_H
#define _NERV_H

/// Arduino pin.
typedef const uint8_t pin_t;

/// Input-output port.
typedef struct Port {
  volatile uint8_t *ddr, *port, *pin;
} port_t;

/////////////////////////////////////////////////////////
// Функции для реализации под конкретную модель МК.

// Digital
inline port_t const *_get_port(pin_t pin);
inline uint8_t _get_port_pin(pin_t pin);

// PWM
inline void _init_fast_pwm(const uint8_t timer);
inline void _init_pwm_pin(const uint8_t pin);
inline void _set_pwm_on_pin(pin_t pin, const uint8_t value);

// Timers
inline void _stop_timer(const uint8_t timer);

/////////////////////////////////////////////////////////
/// Подключения используемой реализации.

#if defined(__AVR_ATtiny2313A__) || defined(__AVR_ATtiny2313__)
#include "./devices/attiny2313.c"
#endif // !__AVR_ATtiny2313A__

#if defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__)
#include "./devices/attiny13.c"
#endif // defined(__AVR_ATtiny13__)

/////////////////////////////////////////////////////////

#include "util.h"
#include "common.c"
#include "digital.c"
#include "analog.c"

#endif // !_NERV_H
