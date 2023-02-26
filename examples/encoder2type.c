#include "../nerv.h"

enum { KEY = 6, LED_LEFT = 7, LED_RIGHT = 10, S1 = 8, S2 = 9 };

typedef struct EncoderType2 {
  uint8_t key, s1, s2;
  bool last_s1_state;
} encodert2_t;

inline encodert2_t create_encoder(const uint8_t key, const uint8_t s1,
                                  const uint8_t s2) {
  init_pin(key, INPUT);
  init_pin(s1, INPUT);
  init_pin(s2, INPUT);

  encodert2_t e = {key, s1, s2, 1};
  return e;
}

typedef enum { LEFT, RIGHT, STOP } dir_t;

inline dir_t is_turn(encodert2_t *encoder) {
  const bool current_s1_state = digital_read(encoder->s1);
  const bool last_s1_state = encoder->last_s1_state;

  encoder->last_s1_state = current_s1_state;

  if (last_s1_state && !current_s1_state)
    return digital_read(encoder->s2) ? LEFT : RIGHT;

  return STOP;
}

inline bool is_pressed(const encodert2_t *encoder) {
  return !digital_read(encoder->key);
}

void _start() {
  init_pin(LED_LEFT, OUTPUT);
  init_pin(LED_RIGHT, OUTPUT);

  encodert2_t encoder = create_encoder(KEY, S1, S2);

  while (1) {
    switch (is_turn(&encoder)) {
    case LEFT:
      digital_write(LED_LEFT, HIGH);
      digital_write(LED_RIGHT, LOW);
      break;
    case RIGHT:
      digital_write(LED_RIGHT, HIGH);
      digital_write(LED_LEFT, LOW);
    case STOP:
      if (is_pressed(&encoder)) {
        digital_write(LED_RIGHT, LOW);
        digital_write(LED_LEFT, LOW);
      }
      break;
    }
  }
}
