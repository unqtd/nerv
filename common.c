#include "nerv.h"

#ifndef _COMMON_H
#define _COMMON_H

typedef enum PinMode {
  // Input
  INPUT,
  INPUT_PULLUP,
  // Output
  OUTPUT,
  OUTPUT_ANALOG
} pinmode_t;

/// Устанавливает режим работы пина.
inline void init_pin(pin_t pin, const pinmode_t mode) {
  port_t const *port = _get_port(pin);
  if (port == NULL)
    return;

  const uint8_t bit = _get_port_pin(pin);
  switch (mode) {
  case INPUT_PULLUP:
    *port->port |= bit(bit);
  case INPUT:
    *port->ddr &= ~bit(bit);
    break;
  case OUTPUT_ANALOG:
    _init_pwm_pin(pin);
  case OUTPUT:
    *port->ddr |= bit(bit);
    break;
  }
}

/// Настраивает выбранный таймер для работы с ШИМ.
inline void init_pwm(const uint8_t timer, const prescaler_t prescaler) {
  // ...
  _init_pwm(timer);
  _init_pwm_prescaler(timer, prescaler);
}

#define PWM_SCOPE(TIMER, PRESCALER, BLOCK)                                     \
  {                                                                            \
    init_pwm(TIMER, PRESCALER);                                                \
    BLOCK                                                                      \
    _turn_of_pwm(TIMER);                                                       \
  }

#endif // !DEBUG
