#include "Brick.h"
#include "Ball.h"
#include <iostream>
#include <cmath>
#include "../core/GameManager.h"
#include "../engine/events/EventsManager.h"
#include <SFML/Graphics.hpp>

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->shape = new sf::RectangleShape({ width, height });
	this->drawable = this->shape;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->transformable = this->shape;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->transformable->setPosition(x, y);
}

Brick::~Brick()
{
	std::cout << "Brick Destroyed" << std::endl;
	delete this->shape;
}

void Brick::update(float deltaTime)
{
}

void Brick::onCollision(sf::Vector2f collisionSide)
{
	this->health -= 1;
	GameManager::eventManager.trigger(ENVIRONNEMENT_UPDATE, BRICK_TOUCH);
	switch (this->health)
	{
	case 4:
		this->shape->setFillColor(sf::Color::Green);
		break;

	case 3:
		this->shape->setFillColor(sf::Color::Blue);
		break;

	case 2:
		this->shape->setFillColor(sf::Color::Magenta);
		break;

	case 1:
		this->shape->setFillColor(sf::Color::Red);
		break;

	case 0:
		GameManager::eventManager.trigger(ENVIRONNEMENT_UPDATE, BRICK_DESTROY); 
		GameManager::killGameObject(this);
		break;

	default:
		this->shape->setFillColor(sf::Color::White);
		break;
	}
}
