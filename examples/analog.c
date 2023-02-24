#include "../nerv.h"

#define P 2
#define LED 0

inline long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {
  init_pwm(0);

  init_pin(LED, OUTPUT_ANALOG);
  init_pin(P, INPUT_ANALOG);

  while (1) {
    WITH_ADC({
      const uint16_t p_scale = analog_read(P);
      analog_write(LED, map(p_scale, 0, 1023, 0, 255));
    })
  }
}
