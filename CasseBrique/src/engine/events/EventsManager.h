#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
#include <iostream>

class VoidClass {};

namespace sf {
	class Event;
}

typedef enum EventTypes {
	KEY_PRESSED = 0,
	KEY_RELEASED,
	MOUSE_MOTION,
	MOUSE_CLICK,
	ENVIRONNEMENT_UPDATE,
	EVENT_TYPES_AMOUNT
} EventType;

typedef enum EventNames {
	KEY_A_PRESSED = 0,
	KEY_A_RELEASED,
	ESCAPE,
	CLOSE_WINDOW,
	MOUSE_RIGHT_PRESSED,
	EVENT_NAMES_AMOUNT
} EventName;

typedef enum EventCallbackReturns {
	SUCCESS = 0,
	FAILURE,
	STOP_PROPAGATE,
	EVENT_CALLBACK_RETURNS_AMOUNT
} EventCallbackReturn;

using EventCallback = std::function<int()>; // a = subscribe(std::bind(functionPointer, instanceAdress)) //std::function<int()> callback = std::bind(functionPointer, instanceAdress)


struct EventCallbackData
{
	void* instanceAdress;
	void(VoidClass::* methodPointer)() ;
	EventCallback callback;
};


class EventsManager
{
public:
	EventsManager();
	~EventsManager();

	template<typename T>
	void subscribe(EventName eventName, T* instanceAdress, int(T::* methodPointer)())
	{
		EventCallbackData eventCallbackData;
		eventCallbackData.instanceAdress = (void*) instanceAdress;
		eventCallbackData.methodPointer = (void(VoidClass::*)()) methodPointer;
		eventCallbackData.callback = std::bind(methodPointer, instanceAdress);
		eventCallbacksMap[eventName].push_back(eventCallbackData);
	}

	template<typename T>
	void unsubscribe(EventName eventName, T* instanceAdress, int(T::* methodPointer)())
	{
		std::vector<EventCallbackData>* eventCallbacks = &eventCallbacksMap[eventName];
		void* castedInstanceAdress = (void*)instanceAdress;
		void(VoidClass::*castedMethodPointer)() = (void(VoidClass::*)()) methodPointer;
		int index = 0;
		for (EventCallbackData callbackData: *eventCallbacks) {
			if (callbackData.instanceAdress == castedInstanceAdress && callbackData.methodPointer == castedMethodPointer) {
				eventCallbacks->erase(eventCallbacks->begin() + index);
			}
			index++;
		}
	}

	void handleEvents();

	void trigger(EventType eventType, EventName eventName);

private:
	sf::Event event;
	std::unordered_map<EventName, std::vector<EventCallbackData>> eventCallbacksMap;
};

