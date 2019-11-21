#include <global.h>

void setup() {
	Serial.begin(9600);
	Screen::setup();
}

void loop() {
	Screen::loop();
	Comm::read_serial();
}