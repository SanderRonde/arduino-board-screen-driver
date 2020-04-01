#include <global.h>
#include <telnet.h>

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
			LOGN("Waking screen");

			String dim = "sleep=0";
			Screen::get_screen().sendCommand(dim.c_str());
			is_dimmed = false;
		}

		void dim_screen() {
			if (is_dimmed) return;
			LOGN("Dimming screen");

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

		void handle_message(String data) {
			if (data[0] == 's') {
				if (data[1] == '1') {
					enable_dimming = false;
					wake_screen();
				} else if (data[1] == '0') {
					enable_dimming = true;
					check_dim();
				}
			}
		}
	}
}