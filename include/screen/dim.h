#pragma once

#include <screen/screen.h>
#include <Arduino.h>
#include <string.h>

namespace Screen {
	namespace Dim {
		void on_touch();
		void check_dim();
		void handle_serial(String str);
	}
}