#include "GameManager.h"
//#include "../entities/GameObject.h"

/*GameManager::GameManager(sf::RenderWindow* window)
{
	GameManager::window = window;
}*/

#include <SFML/Graphics.hpp>
#include "../entities/GameObject.h"
#include "../entities/Canon.h"


std::vector<GameObject*> GameManager::gameObjects;
sf::RenderWindow* GameManager::window;
sf::Mouse* GameManager::mouse;

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
        for (int i = 0; i < GameManager::gameObjects.size(); i++)
        {
            gameObjects[i]->update(deltaTime);
        }
    
}
void GameManager::spawnGameObject(GameObject* gameObject)
{
	GameManager::gameObjects.push_back(gameObject);
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
