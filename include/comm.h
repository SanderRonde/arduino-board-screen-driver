#include <ws.h>

#pragma once

namespace Comm {
	void ws_event(String event, String type, String data);
	extern SemiWebSocket ws;

	void loop();
	void setup();
}