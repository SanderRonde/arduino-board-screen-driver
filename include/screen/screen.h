#pragma once

#include <screen/screen_comm.h>
#include <Nextion.h>
#include <Arduino.h>
#include <string.h>
#include <comm.h>

namespace Screen {
	Nextion get_screen();

	void setup();
	void loop();
}