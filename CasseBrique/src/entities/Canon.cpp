#include "Canon.h"
#include "Ball.h"
#include <iostream>
#include <cmath>

Canon::Canon(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangle->setPosition(x, y);
	this->rectangle->setOrigin(width / 2, height);
}

Canon::~Canon()
{
	delete this->rectangle;
}

void Canon::updateShape(int mousex, int mousey)
{
	float xPoint = std::abs(position.x);
	float yPoint = std::abs(position.y);

	float radianAngle = atan2f(xPoint - mousex, yPoint - mousey);
	float degreeAngle = convertRadiansToDegrees(radianAngle);

	this->orientation.x = xPoint - mousex;
	this->orientation.y = yPoint - mousey;

	if (degreeAngle < 90 and degreeAngle > -90)
	{
		this->rectangle->setRotation(-degreeAngle);
	}


}

void Canon::launchBall(Ball* ball)
{
	sf::Vector2f normalizeOrientation = normalize(this->orientation);
	ball->setPosition(this->rectangle->getPosition().x - normalizeOrientation.x * size.y, this->rectangle->getPosition().y - normalizeOrientation.y * size.y);
	ball->setDirection(-normalizeOrientation.x, -normalizeOrientation.y);
}