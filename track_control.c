#include "track_control.h"

/* Signal states */
enum LightState up99, up100, up101, down99, down100, down101, siding100;
/* Train presence sensors */
/* Assume these are in the same order as the variables above */
enum TrainState state[7];

void init() {
  int i;

  for(i = 0; i < 7; i++) {
    state[i] = CLEAR;
  }
  
  up99 = GREEN;
  up100 = GREEN;
  down101 = GREEN;
  down100 = GREEN;
  siding100 = RED;
  
}

void setState(int i, enum TrainState s) {
  state[i] = s;
}

void checkStates() {
  /* UP track */
  if(state[1] == PRESENT) {
    up99 = RED;
  } else if(state[2] == PRESENT) {
    up99 = AMBER;
    up100 = RED;
  } else {
    up99 = GREEN;
    up100 = GREEN;
    up101 = GREEN;
  }
  
  /* DOWN track */
  if(state[4] == PRESENT) {
    down100 = RED;
    down101 = AMBER;
  } else if(state[3] == PRESENT) {
    down99=GREEN;
    down100 = RED;
    down101 = AMBER;
  } else {
    down99=GREEN;
    down100 = GREEN;
    down101 = GREEN;
  }
