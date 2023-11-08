#pragma once
#include <vector>

#include <SFML/Graphics.hpp>

class GameObject;

class GameManager
{
public:
	GameManager(sf::RenderWindow*window);
	~GameManager();
	void render();
	void update(float deltaTime);
private:
	std::vector<GameObject*> gameObjects;
	sf::RenderWindow* window;
};
