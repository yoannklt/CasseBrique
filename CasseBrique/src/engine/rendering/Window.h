#pragma once
#include <SFML/Graphics/RenderWindow.hpp>


/// <summary>
/// Class Wrapping the sf::RenderWindow into a custom Class
/// </summary>
class Window {
public:
	Window(int width, int height, const char* title = "New Project");
	~Window();
	int closeWindow();
	inline sf::RenderWindow getWindow() { return window; };

private:
	sf::RenderWindow window;
};