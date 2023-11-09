#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>;

namespace sf 
{
	class RenderWindow;
	class Mouse;
}

class GameObject;

class GameManager
{
public:
	
	//~GameManager();
	static void render();
	static void update(float deltaTime);
	static void spawnGameObject(GameObject* gameObject);
	static sf::Vector2i getMousePosition();
	static void setWindow(sf::RenderWindow* window);

private:
	//GameManager(sf::RenderWindow* window);

	static std::vector<GameObject*> gameObjects;
	static sf::RenderWindow* window;
	static sf::Mouse* mouse;
};
