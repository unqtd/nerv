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

// Digital
inline port_t const *_get_port(pin_t pin);
inline uint8_t _get_port_pin(pin_t pin);

// PWM
inline void _init_fast_pwm(const uint8_t timer);
inline void _init_pwm_pin(const uint8_t pin);
inline void _set_pwm_on_pin(pin_t pin, const uint8_t value);

// Timers
inline void _stop_timer(const uint8_t timer);

#if defined(__AVR_ATtiny2313A__) || defined(__AVR_ATtiny2313__)
#include "./devices/2313.c"
#endif // !__AVR_ATtiny2313A__

#include "common.c"
#include "digital.c"
#include "analog.c"
#include "util.h"

#endif // !_NERV_H
