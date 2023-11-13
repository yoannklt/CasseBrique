#include "Brick.h"
#include "Ball.h"
#include <iostream>
#include <cmath>
#include "../core/GameManager.h"
#include <SFML/Graphics.hpp>

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setPosition(x, y);
}

Brick::~Brick()
{
}

void Brick::update(float deltaTime)
{
}

void Brick::onCollision(sf::Vector2f collisionSide)
{
	this->health -= 1;
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
		GameManager::killGameObject(this);
		break;

	default:
		this->shape->setFillColor(sf::Color::White);
		break;
	}
}
