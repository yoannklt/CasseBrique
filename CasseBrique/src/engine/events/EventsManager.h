#pragma once
#include <unordered_map>
#include <vector>
#include <SFML/Graphics.hpp>

typedef enum EventTypes {
	KEY_PRESSED = 0,
	KEY_RELEASED,
	MOUSE_MOTION,
	MOUSE_CLICK,
	EVENT_TYPES_AMOUNT
} EventType;

typedef enum EventNames {
	KEY_A_PRESSED = 0,
	KEY_A_RELEASED,
	ESCAPE,
	EVENT_NAMES_AMOUNT
} EventName;

sf::Event::EventName


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


std::unordered_map<EventName, std::vector<callback>> eventNameMap
std::unordered_map<sf::Keyboard::Key, EventName> keyboardMap{KeyA pressed}
std::unordered_map<sf::Mouse::Key, EventName> mouseMap{rightclick pressed}

switch eventType
case MouseType:
	callbackList = eventNameMap.find(mouseMap[event.key.code])
		for callback in callback list
			callback();

	EventName 