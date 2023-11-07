#pragma once
#include <unordered_map>
#include <vector>
#include <functional>

typedef enum EventTypes {
	KEY_PRESSED = 0,
	KEY_RELEASED,
	MOUSE_MOTION,
	MOUSE_CLICK,
	EVENT_TYPES_AMOUNT
} EventType;

typedef enum EventNames {
	EVENT_NAME_1 = 0,
	EVENT_NAMES_AMOUNT
} EventName;

typedef enum KeyNames {
	KEY_A = 0,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_SPACE,
	KEY_ENTER,
	KEY_ESCAPE,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_NAMES_AMOUNT
} KeyName;

typedef enum EventCallbackReturns {
	SUCCESS = 0,
	FAILURE,
	STOP_PROPAGATE,
	EVENT_CALLBACK_RETURNS_AMOUNT
} EventCallbackReturn;

using EventCallback = int(*)(); 

class EventsManager
{
public:
	void subscribe(EventName eventName, EventCallback);
	void unsubscribe(EventName eventName, EventCallback);
	void trigger(EventType eventType, EventName eventName);

private:
	std::unordered_map<EventType, std::vector<EventCallback>> eventCallbacksMap;
};