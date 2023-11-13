#include "GameManager.h"
#include "../systems/Collisions.h"

#include <SFML/Graphics.hpp>
#include "../entities/GameObject.h"
#include "../entities/MovingObject.h"
#include "../entities/Canon.h"


std::vector<GameObject*> GameManager::gameObjects;
std::vector<GameObject*> GameManager::gameObjectsToDelete;
sf::RenderWindow* GameManager::window;
sf::Mouse* GameManager::mouse;
Collisions GameManager::collisions;

void GameManager::render()
{
	GameManager::window->clear();
	for (int i = 0; i < GameManager::gameObjects.size(); i++)
	{
		GameManager::window->draw(*gameObjects[i]->getShape());
	}
	GameManager::window->display();
}


void GameManager::update(float deltaTime)
{
    sf::Event oEvent;
    Canon* canon = (Canon*)GameManager::gameObjects[0];
    while (GameManager::window->pollEvent(oEvent))
    {
        switch (oEvent.type)
        {
        case sf::Event::Closed:
            GameManager::window->close();
            break;

        case sf::Event::MouseButtonPressed:
            switch (oEvent.mouseButton.button)
            {
            case sf::Mouse::Left:
                
                canon->launchBall();
                //std::cout << "Left click detected" << std::endl;
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
    GameManager::collisions.checkCollisions();
    for (int i = 0; i < GameManager::gameObjects.size(); i++)
    {
        gameObjects[i]->update(deltaTime);
    }
    deleteGameObjectsAtEndOfUpdate();
}

void GameManager::spawnGameObject(GameObject* gameObject)
{
	GameManager::gameObjects.push_back(gameObject);
}

void GameManager::killGameObject(GameObject* gameObject)
{
    GameManager::gameObjects.erase(std::remove(GameManager::gameObjects.begin(), GameManager::gameObjects.end(), gameObject), GameManager::gameObjects.end());
    GameManager::collisions.unregisterStaticBody(gameObject);
    GameManager::collisions.unregisterRigidBody((MovingObject*)gameObject);
    GameManager::gameObjectsToDelete.push_back(gameObject);
}

void GameManager::deleteGameObjectsAtEndOfUpdate() {
    for (GameObject* gameObject : GameManager::gameObjectsToDelete) {
        GameManager::gameObjectsToDelete.erase(std::remove(GameManager::gameObjectsToDelete.begin(), GameManager::gameObjectsToDelete.end(), gameObject), GameManager::gameObjectsToDelete.end());
        delete gameObject;
    }
}

void GameManager::spawnStaticBody(GameObject* staticBody)
{
    GameManager::spawnGameObject(staticBody);
    GameManager::collisions.registerStaticBody(staticBody);
}

void GameManager::spawnRigidBody(MovingObject* rigidBody)
{
    GameManager::spawnGameObject(rigidBody);
    GameManager::collisions.registerRigidBody(rigidBody);
}

void GameManager::registerStaticBody(GameObject* staticBody)
{
    GameManager::collisions.registerStaticBody(staticBody);
}

void GameManager::registerRigidBody(MovingObject* rigidBody) {
    GameManager::collisions.registerRigidBody(rigidBody);
}

sf::Vector2i GameManager::getMousePosition()
{
	sf::Vector2i mousePosition = GameManager::mouse->getPosition(*GameManager::window);
	return mousePosition;
}

void GameManager::setWindow(sf::RenderWindow* window)
{
	GameManager::window = window;
}
