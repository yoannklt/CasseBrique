#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sf 
{
	class Mouse;
}

class GameObject;
class MovingObject;
class Collisions;
class EventsManager;
class Window;
class Text;

class GameManager
{
public:
	
	//~GameManager();
	static void render();
	static void update(float deltaTime);
	static void spawnGameObject(GameObject* gameObject);
	static void killGameObject(GameObject* gameObject);
	static void spawnStaticBody(GameObject* staticBody);
	static void spawnRigidBody(MovingObject* rigidBody);
	static void registerStaticBody(GameObject* staticBody);
	static void registerRigidBody(MovingObject* rigidBody);
	static sf::Vector2i getMousePosition();
	static void setWindow(Window* window);
	static Window* getWindow();
	static EventsManager eventManager;


private:
	//GameManager(sf::RenderWindow* window););

	static void deleteGameObjectsAtEndOfUpdate();


	static std::vector<GameObject*> gameObjects;
	static std::vector<GameObject*> gameObjectsToDelete;

	static Collisions collisions;
	
	static Window* window;
	static sf::Mouse* mouse;
};
