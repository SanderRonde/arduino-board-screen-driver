#include <global.h>

namespace Comm {
	void handle_serial(String str) {
		Screen::Comm::handle_serial(str);
		IR::Comm::handle_serial(str);
	}

	void read_serial() {
		static String str = "";
		while (Serial.available()) {
			char read = (char) Serial.read();
			if (read == '\n') {
				Serial.println("Got serial str");
				Serial.println(str);
				handle_serial(str);
				str = "";
			} else {
				str += String(read);
			}
		}
	}
}