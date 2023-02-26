#include "../nerv.h"

#define P 2
#define LED 0

// inline long map(long x, long in_min, long in_max, long out_min, long out_max)
// {
//   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }

int main() {
  init_pwm(0, AUTO_PRESCALE, PHASE_CORRECT);
  const adc_t adc = init_adc(ADC8BIT);

  init_pin(LED, OUTPUT_ANALOG);

  while (1) {
    const uint16_t p_scale = analog_read(adc, P);
    analog_write(LED, p_scale);
  }
}
