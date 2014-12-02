#include <DFRobot_utility.h>
#include <utility/rgbLed.h>

rgbLed led (3,4,5);

void setup () {
}

int a = 0;

void loop () {
        a++;
        if (a > 360) 
                a = 0;
        led.setColor (a);
        delay (1);
}


