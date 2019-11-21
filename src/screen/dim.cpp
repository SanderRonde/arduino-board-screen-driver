#include <global.h>

#define DO_DIM 1
#define DIM_TIME 20
#define DIM_BRIGHTNESS 1
#define NORMAL_BRIGHTNESS 100

namespace Screen {
	namespace Dim {
		unsigned long last_touch = 0;
		bool is_dimmed = false;
		bool enable_dimming = true;
		void wake_screen() {
			if (!is_dimmed) return;
			Serial.println("# Waking screen");

			String dim = "sleep=0";
			Screen::get_screen().sendCommand(dim.c_str());
			is_dimmed = false;
		}

		void dim_screen() {
			if (is_dimmed) return;
			Serial.println("# Dimming screen");

			String dim = "sleep=1";
			Screen::get_screen().sendCommand(dim.c_str());
			is_dimmed = true;
		}

		void on_touch() {
			last_touch = millis();
			if (is_dimmed) {
				wake_screen();
			}
		}

		void check_dim() {
			if (!DO_DIM || !enable_dimming || is_dimmed) return;

			if (millis() - last_touch > DIM_TIME * 1000) {
				dim_screen();
			}
		}

		void handle_serial(String str) {
			if (str[0] == 's') {
				Serial.println("Got s serial");
				if (str[1] == '1') {
					Serial.println("Dimming");
					enable_dimming = false;
					wake_screen();
				} else if (str[1] == '0') {
					Serial.println("Not Dimming");
					enable_dimming = true;
					check_dim();
				}
			}
		}
	}
}