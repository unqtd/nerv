#include "../nerv.h"
#include <util/delay.h>

int main(void) {
  init_pin(2, OUTPUT);

  while (1) {
    toggle(2);
    _delay_ms(1000);
  }
}
