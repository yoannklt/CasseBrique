#include "Window.h"
#include "../../core/GameManager.h"
#include "../events/EventsManager.h"

Window::Window(int width, int height, const char* title) : window(sf::VideoMode(width, height), title) {
	GameManager::eventManager.subscribe<Window>(CLOSE_WINDOW_BUTTON, this, &Window::closeWindow);
}

Window::~Window()
{
}

int Window::closeWindow() {
	this->window.close();
	return 0;
}

