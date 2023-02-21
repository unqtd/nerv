#include "../nerv.h"

#define BTN 4
#define LED 1

int main() {
  init_pin(BTN, INPUT_PULLUP);
  init_pin(LED, OUTPUT);

  while (1) {
    const bool btn_state = digital_read(BTN);
    digital_write(LED, !btn_state);
  }
}
