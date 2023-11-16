#include "Brick.h"
#include "Ball.h"
#include <iostream>
#include <cmath>
#include "../core/GameManager.h"
#include "../engine/events/EventsManager.h"
#include "../engine/textures/TextureManager.h"
#include <SFML/Graphics.hpp>

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	// SHAPE / DRAWABLE / TRANSFORMABLE INITIALIZATION
	this->shape = new sf::RectangleShape({ width, height });
	this->transformable = this->shape;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->transformable->setPosition(x, y);

	// SPRITE SHIT
	this->sprite = new sf::Sprite(*TextureManager::getTexture("0.jpg"));
	this->sprite->setScale(this->size.x / this->sprite->getGlobalBounds().width, this->size.y / this->sprite->getGlobalBounds().height);
	this->drawable = this->sprite;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });

	this->sprite->setPosition(this->position);

	// RANDOM COLOR SYSTEM
	int randomColorValue = std::rand() % 3 + 1;
	switch (randomColorValue)
	{
	case 1:
		this->color = new sf::Color({ 255 , 0, 0 });
		this->colorValue = &this->color->r;
		break;

	case 2:
		this->color = new sf::Color({ 0, 255, 0 });
		this->colorValue = &this->color->g;
		break;

	case 3:
		this->color = new sf::Color({ 0, 0, 255 });
		this->colorValue = &this->color->b;
		break;

	default:
		break;
	}
	this->shape->setFillColor(*color);
}

Brick::~Brick()
{
	// std::cout << "Brick Destroyed" << std::endl;
	delete this->shape;
	delete this->sprite;
}

void Brick::update(float deltaTime)
{
}

void Brick::onCollision(sf::Vector2f collisionSide)
{
	this->health -= 1;
	this->imageKey = this->maxHealth - this->health;
	if (this->health == 0)
	{
		GameManager::killGameObject(this);
		GameManager::eventManager.trigger(BRICK_DESTROY);
		return;
	}

	this->sprite->setTexture(*TextureManager::getTexture(std::to_string(imageKey) + ".jpg"));
	*this->colorValue = 255 * this->health / this->maxHealth;

	GameManager::eventManager.trigger(BRICK_TOUCH);
	this->shape->setFillColor(*color);
}
