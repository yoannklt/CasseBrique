#include "EventsManager.h"
#include "../../core/GameManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

EventsManager::EventsManager()
{
}

EventsManager::~EventsManager()
{
}

void EventsManager::handleEvents()
{

    while (GameManager::getWindow()->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::MouseButtonPressed:
            trigger(EventType::ENVIRONNEMENT_UPDATE, EventName::MOUSE_LEFT_PRESSED);
            break;
        default:
            break;
        }
    }
}

void EventsManager::trigger(EventType eventType, EventName eventName)
{
	for (EventCallbackData callbackData : eventCallbacksMap[eventName])
	{
        // std::cout << "calling callback for event " << eventName << std::endl;
		callbackData.callback();
	}
}