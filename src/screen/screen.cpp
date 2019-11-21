#include <global.h>

namespace Screen {
	SoftwareSerial nextion(4, 5);
	Nextion myNextion(nextion, 9600);

	void setup() {
		myNextion.init();
	}

	Nextion get_screen() {
		return myNextion;
	}

	void loop() {
		String message = myNextion.listen(); //check for message
		if (message != "") { // if a message is received...
			Screen::Touch::handle_touch_message(message);
		}
		Screen::Dim::check_dim();
	}
}