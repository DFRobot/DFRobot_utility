#include <DFRobot_utility.h>

digitalOut led (13);
digitalIn button (12);

void setup () {
}

void loop () {
  led = button;
}

/*
 *  digitalWrite (led, digitalRead (button));
 */
