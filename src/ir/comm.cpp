#include <global.h>

namespace IR {
	namespace Comm {
		void handle_serial(String str) {
			if (str[0] == 'i') {
				IR::toggle_beamer_power();
			}
		}
	}
}