/*#include "EventsManager.h"

EventsManager::EventsManager()
{
}

EventsManager::~EventsManager()
{
}


void EventsManager::subscribe(EventName eventName, EventCallback eventCallback)
{

	eventCallbacksMap[eventName].push_back(eventCallback);
}

void EventsManager::unsubscribe(EventName eventName, EventCallback eventCallback)
{
	std::vector<EventCallback> callbacks = eventCallbacksMap[eventName];
	callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), eventCallback), callbacks.end());
}


void EventsManager::trigger(EventType eventType, EventName eventName)
{
	for (EventCallback callback : eventCallbacksMap[eventName])
	{
		callback();
	}
}

*/


