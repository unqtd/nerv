#define __AVR_ATtiny2313A__
#include "../nerv.h"
#include <util/delay.h>

#define LED 13
#define LED_OVERFLOW_FLAG 7

static void blink_by_overflow_flag();

void _start() {
  init_pwm(1, AUTO_PRESCALE);

  init_pin(LED, OUTPUT_ANALOG);
  init_pin(LED_OVERFLOW_FLAG, OUTPUT);

  while (1) {
    for (unsigned int scale = 0; scale <= 1024; scale++) {
      analog_write(LED, scale);
      _delay_ms(3);
    }

    blink_by_overflow_flag();
  }
}

static void blink_by_overflow_flag() {
  digital_write(LED_OVERFLOW_FLAG, HIGH);
  _delay_ms(500);
  digital_write(LED_OVERFLOW_FLAG, LOW);
}
