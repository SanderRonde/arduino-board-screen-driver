#pragma once

#include <Arduino.h>
#include <String.h>

namespace Util {
	char** split_string(String str);
	void free_split(char** strings);
}