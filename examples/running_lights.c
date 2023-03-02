#include "../nerv.h"
#include "util/delay.h"

inline void init_pins_range(pin_t start, pin_t end, const pinmode_t mode) {
  for (uint8_t pin = start; pin <= end; pin++)
    init_pin(pin, mode);
}

#define START 0
#define END 9

#define BTN 10

int main() {
  init_pins_range(START, END, OUTPUT);
  init_pin(BTN, INPUT);

  int8_t current_led_pin = 0;
  int8_t previous_led_pin = 0;
  enum { LEFT, RIGHT } direction = RIGHT;

  while (1) {
    if (digital_read(BTN))
      direction = direction == LEFT ? RIGHT : LEFT;

    digital_write(previous_led_pin, LOW);
    digital_write(current_led_pin, HIGH);
    _delay_ms(200);

    previous_led_pin = current_led_pin;
    current_led_pin =
        direction == LEFT ? current_led_pin - 1 : current_led_pin + 1;

    if (current_led_pin < START)
      current_led_pin = END;
    else if (current_led_pin > END)
      current_led_pin = START;
  }
}
