#include <screen/global.h>
#include <ArduinoOTA.h>
#include <Arduino.h>
#include <telnet.h>
#include <util.h>
#include <ota.h>
#include <net.h>

void setup() {
	Serial.begin(115200);
	Serial.println("Booting");

	// Setup telnet
	Telnet::setup("screen-board");

	// Setup OTA and wait
	OTA::setup();
	LOGN("Booted. Waiting for possible OTAs");
	OTA::wait_for_otas();
	LOGN("Stopped waiting");

	// Setup the rest
	Net::setup();
	Comm::setup();
	Screen::setup();

	// Done
	LOGN("Booted");
}

void loop() {
	OTA::loop();
	Screen::loop();
	Comm::loop();
	Telnet::loop();
}