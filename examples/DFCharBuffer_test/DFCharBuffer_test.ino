#include <DFRobot_utility.h>
#include <utility/DFCharBuffer.h>

DFCharBuffer mybuf (10);

void setup () {
	for (int i=0; i<6; i++) {
		mybuf.writeFromHead (i+'a');
	}
}

void loop () {
	for (int i=0; i<10; i++) {
		int value = mybuf.readFromTail ();
		if (value > 0) {
			Serial.println ((char)value);
		}
	}
	delay (1000);
}

