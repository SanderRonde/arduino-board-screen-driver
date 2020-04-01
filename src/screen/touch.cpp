#include <global.h>
#include <telnet.h>
#include <comm.h>

namespace Screen {
	namespace Touch {
		typedef struct instruction {
			const char* name;
			int value;
		} instruction_t;

		instruction_t ids[] = {
			{ "", -1 },
			{ "", -1 },
			{ "room.lights.ceiling", 1 },
			{ "", -1 },
			{ "", -1 },
			{ "", -1 },
			{ "room.lights.ceiling", 0 },
			{ "room.lights.nightstand", 1 },
			{ "room.lights.nightstand", 0 },
			{ "room.speakers.couch", 1 },
			{ "room.speakers.couch", 0 },
			{ "room.speakers.desk", 1 },
			{ "room.speakers.desk", 0 },
			{ "room.lights", 1 },
			{ "room.lights", 0 },
			{ "room.speakers", 1 },
			{ "room.speakers", 0 }
		};

		typedef struct msg {
			long event_type;
			long screen;
			long id;
			long action;
			char** strings;
		} msg_t;

		void handle_click(msg_t* msg) {
			if (msg->id == 0) return;

			instruction_t ins = ids[msg->id];
			if (ins.value == -1) return;

			char* message = (char*) malloc(sizeof(char) * 100);
			sprintf(message, "%s %d", ins.name, ins.value);
			Comm::ws.send_message("button", message);
			
			free(message);
		}

		msg_t* parse_msg(String message) {
			char** split = Util::split_string(message);
			msg_t* msg = (msg_t*) malloc(sizeof(msg_t));

			msg->event_type = strtol(split[0], NULL, 10);
			msg->screen = strtol(split[1], NULL, 10);
			msg->id = strtol(split[2], NULL, 16);
			msg->action = strtol(split[3], NULL, 10);
			msg->strings = split;
			
			return msg;
		}

		void free_msg(msg_t* msg) {
			Util::free_split(msg->strings);
			free(msg);
		}

		void handle_touch_message(String message) {
			msg_t* msg = parse_msg(message);

			String log_msg = "# " + message;
			LOGF("Touch: %s\n", log_msg.c_str());

			if (msg->event_type == 65) {
				Screen::Dim::on_touch();
				handle_click(msg);
			} else if (msg->event_type == 68) {
				Screen::Dim::on_touch();
			}

			free_msg(msg);
		}
	}
}