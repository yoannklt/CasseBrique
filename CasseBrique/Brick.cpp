#include "Brick.h"
#include "Ball.h"
#include <iostream>
#include <cmath>

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangle->setPosition(x, y);
	this->rectangle->setOrigin(width / 2, height);
}

Brick::~Brick()
{
	delete this->rectangle;
}

void Brick::updateShape(int mousex, int mousey)
{
	float xPoint = std::abs(position[0]);
	float yPoint = std::abs(position[1] + size[1] + size[0]/2);

	float radianAngle = atan2f(xPoint - mousex, yPoint - mousey);
	float degreeAngle = convertRadiansToDegrees(radianAngle);


	if (degreeAngle < 90 and degreeAngle > -90)
	{
		this->rectangle->setRotation(-degreeAngle);
	}

		
}
