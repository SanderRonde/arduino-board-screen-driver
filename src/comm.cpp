#include <global.h>
#include <config.h>
#include <telnet.h>
#include <ws.h>

namespace Comm {
	void ws_event(String event, String type, String data);
	SemiWebSocket ws = SemiWebSocket(ws_event, 5000, 60 * 1000);

	void handle_messag(String type, String data) {
		if (type == "valChange") {
			Screen::ScreenComm::handle_message(data);
		} else {
			LOGF("Unknown message %s, %s\n", type.c_str(), data.c_str());
		}
	}

	void ws_event(String event, String type, String data) {
		if (event == "closed") {
			LOGF("[WSc] Disconnected!\n");
		} else if (event == "connected") {
			LOGF("[WSc] Connected\n");
			ws.send_message("listen", KEY_NAME);
		} else if (event == "message") {
			LOGF("[WSc] get text: %s %s\n", type.c_str(), data.c_str());
			handle_messag(type, data);
		} else {
			LOGF("[WSc] Unknown msg, %s\n", event.c_str());
		}
	}


	void setup() {
		ws.start_server();
		ws.connect();
	}

	void loop() {
		ws.loop();
	}
}