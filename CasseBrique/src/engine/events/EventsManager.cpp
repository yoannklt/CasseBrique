#include "EventsManager.h"

void EventsManager::subscribe(EventName eventName, EventCallback eventCallback)
{
	eventCallbacksMap[eventName].push_back(eventCallback);
}

void EventsManager::unsubscribe(EventName eventName, EventCallback eventCallback)
{
	auto& callbacks = eventCallbacksMap[eventName];
	callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), eventCallback), callbacks.end());
}

void EventsManager::trigger(EventName eventName, Event event)
{
	for (auto& callback : eventCallbacksMap[eventName])
	{
		callback(event);
	}
}

