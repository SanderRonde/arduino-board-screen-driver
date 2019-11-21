#include <global.h>

namespace IR {
	IRsend irsend;

	typedef enum IR_DATA {
		IR_DATA_Help = 0xE17250AF,
		IR_DATA_Power = 0xE172E817,
		IR_DATA_Menu = 0xE17240BF,
		IR_DATA_Esc = 0xE1720AF5,
		IR_DATA_Left = 0xE1728877,
		IR_DATA_Up = 0xE172C837,
		IR_DATA_Right = 0xE17248B7,
		IR_DATA_Down = 0xE17228D7,
		IR_DATA_Select = 0xE1724CB3,
		IR_DATA_Source = 0xE17208F7,
		IR_DATA_AutoImg = 0xE172CC33,
		IR_DATA_PC = 0xE1729867,
		IR_DATA_Video = 0xE17258A7,
		IR_DATA_VolUp = 0xE17210EF,
		IR_DATA_VolDown = 0xE17220DF,
		IR_DATA_KeyStoneUp = 0xE17204FB,
		IR_DATA_KeyStoneDown = 0xE172847B,
		IR_DATA_ZoomIn = 0xE1724AB5,
		IR_DATA_ZoomOut = 0xE172CA35,
		IR_DATA_Mute = 0xE172946B,
		IR_DATA_Blank = 0xE1728C73,
		IR_DATA_Presets = 0xE17234CB,
		IR_DATA_Resize = 0xE1722CD3,
		IR_DATA_Freeze = 0xE172708F,
		IR_DATA_Overscan = 0xE172AC53,
		IR_DATA_SuperMute = 0xE1728A75,
		IR_DATA_Custom = 0xE172D42B
	} IR_DATA_t;

	void send_freq(unsigned long req) {
		irsend.sendNEC(req, 32);
	}

	void toggle_beamer_power() {
		send_freq(IR_DATA_Power);
	}
}