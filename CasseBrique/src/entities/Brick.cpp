#include "Brick.h"
#include "Ball.h"
#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangle->setOrigin(width / 2, height / 2);
}

Brick::~Brick()
{
}

void Brick::update(float deltaTime)
{
}