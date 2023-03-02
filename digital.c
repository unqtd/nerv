#include "nerv.h"

#ifndef _NERV_DIGITAL_H
#define _NERV_DIGITAL_H

enum { HIGH = 1, LOW = 0 };

inline bool digital_read(pin_t pin) {
  port_t const *port = _get_port(pin);
  #ifndef DISABLE_CHECKING
  if (port == NULL)
    return LOW;
  #endif

  // return bit_is_set(*port->pin, _get_port_pin(pin));
  return *port->pin & bit(_get_port_pin(pin));
}

inline void digital_write(pin_t pin, const bool value) {
  port_t const *port = _get_port(pin);
  #ifndef DISABLE_CHECKING
  if (port == NULL)
    return;
  #endif

  if (value)
    *port->port |= bit(_get_port_pin(pin));
  else
    *port->port &= ~bit(_get_port_pin(pin));
}

#ifdef DYN
void dyn_digital_write(pin_t pin, const bool value) {
  digital_write(pin, value);
}
#endif

inline void toggle(pin_t pin) {
  port_t const *port = _get_port(pin);

  #ifndef DISABLE_CHECKING
  if (port == NULL)
    return;
  #endif

  *port->port ^= bit(_get_port_pin(pin));
}

#endif // !_NERV_DIGITAL_H
