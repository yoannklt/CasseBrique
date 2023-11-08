#include "GameManager.h"
#include "../objects/GameObject.h"

GameManager::GameManager(sf::RenderWindow* window)
{
	this->window = window;
}

GameManager::~GameManager()
{
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		delete this->gameObjects[i];
	}
}

void GameManager::render()
{
	this->window->clear();
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		this->window->draw(*gameObjects[i]->shape);
	}
	this->window->display();
}

void GameManager::update(float deltaTime)
{
	for (int i = 0; i < this->gameObjects.size(); i++)
	{
		gameObjects[i]->update(deltaTime);
	}
}

void GameManager::spawnGameObject(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}
