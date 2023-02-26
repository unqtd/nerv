#include <avr/io.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef _NERV_H
#define _NERV_H

/////////////////////////////////////////////////////////
// Настройки по-умолчанию.

// #define PWM_PHASE_CORRECT

/////////////////////////////////////////////////////////

/// Arduino pin.
typedef const uint8_t pin_t;

/// Input-output port.
typedef struct Port {
  volatile uint8_t *ddr, *port, *pin;
} port_t;

typedef enum Prescaler {
  AUTO_PRESCALE
} prescaler_t;

typedef enum {
  FAST_PWM,
  PHASE_CORRECT
} pwm_mode_t;

/////////////////////////////////////////////////////////
// Функции для реализации под конкретную модель МК.

// Digital
inline port_t const *_get_port(pin_t pin);
inline uint8_t _get_port_pin(pin_t pin);

// PWM
inline void _init_pwm_prescaler(const uint8_t timer, const prescaler_t prescaler);
inline void _init_pwm(const uint8_t timer, const pwm_mode_t mode);
inline void _init_pwm_pin(pin_t pin);
inline void _set_pwm_on_pin(pin_t pin, const uint16_t value);
inline void _turn_off_pwm(const uint8_t timer);

// Timers
inline uint8_t _get_timer(pin_t pin);

// ADC
inline uint16_t _adc_read(pin_t pin);

/////////////////////////////////////////////////////////
/// Подключения используемой реализации.

#if defined(__AVR_ATtiny2313A__) || defined(__AVR_ATtiny2313__)
#include "./devices/attiny2313.c"
#elif defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__)
#include "./devices/attiny13.c"
#else
#error Not impl
#endif // defined(__AVR_ATtiny13__)

/////////////////////////////////////////////////////////

#include "util.h"
#include "common.c"
#include "digital.c"
#include "analog.c"

#endif // !_NERV_H
