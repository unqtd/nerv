#include "../nerv.h"
#include <util/delay.h>

int main(void) {
  init_pwm(0);
  init_pin(7, OUTPUT_ANALOG);

  while (1) {
    for (uint8_t i = 0; i < 255; i++) {
      analog_write(7, i);
      _delay_ms(20);
    }
  }
}
