#include "EventsManager.h"

EventsManager::EventsManager()
{
}

EventsManager::~EventsManager()
{
}

void EventsManager::subscribe(EventName eventName, EventCallback eventCallback)
{
	if (this->eventCallbacksMap.find(eventName) != this->eventCallbacksMap.end()) {
		this->eventCallbacksMap[eventName].push_back(eventCallback);
	}
	else {
		this->eventCallbacksMap[eventName] = std::vector<EventCallback>{ eventCallback };
	}
}

void EventsManager::unsubscribe(EventName eventName, EventCallback eventCallback)
{
	std::vector<EventCallback> callbacks = eventCallbacksMap[eventName];
	if (callbacks.size() == 0) {
		callbacks.~vector();
		eventCallbacksMap.erase(eventName);
	}
	else {
		//EventCallback index = std::find(callbacks.begin(), callbacks.end(), eventCallback);
		callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), eventCallback), callbacks.end());
	}
}

void EventsManager::trigger(EventType eventType, EventName eventName)
{
	for (EventCallback callback : eventCallbacksMap[eventName])
	{
		callback();
	}
}