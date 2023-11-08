#pragma once
#include <unordered_map>
#include <vector>

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
	EventsManager();
	~EventsManager();

	void subscribe(EventName eventName, EventCallback);
	void unsubscribe(EventName eventName, EventCallback);
	void trigger(EventType eventType, EventName eventName);

private:
	std::unordered_map<EventName, std::vector<EventCallback>> eventCallbacksMap;
};

