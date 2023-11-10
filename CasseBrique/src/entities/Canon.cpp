#include "Canon.h"
#include "Ball.h"
#include "../core/GameManager.h"

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "../utils/Maths.h"

Canon::Canon(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setPosition(x, y);
	this->shape->setOrigin(width / 2, height);
	//GameManager::spawnGameObject(new Ball(x, y, width, orientation.x, orientation.y, sf::Color::Cyan));
}

Canon::Canon(float x, float y, float width, float height, sf::Color color) : Canon(x, y, width, height)
{
	this->shape->setFillColor(color);
	this->shape->setOutlineThickness(10.f);
	this->shape->setOutlineColor(sf::Color::Cyan);

}

Canon::~Canon()
{
}

void Canon::update(float deltaTime)
{
	sf::Vector2i mousePosition = GameManager::getMousePosition();

	float xPoint = std::abs(position.x);
	float yPoint = std::abs(position.y);

	float radianAngle = atan2f(xPoint - mousePosition.x, yPoint - mousePosition.y);
	float degreeAngle = convertRadiansToDegrees(radianAngle);

	this->orientation.x = xPoint - mousePosition.x;
	this->orientation.y = yPoint - mousePosition.y;

	if (degreeAngle < 90 and degreeAngle > -90)
	{
		this->shape->setRotation(-degreeAngle);
	}
}

void Canon::launchBall()
{
	sf::Vector2f normalizeOrientation = Maths::normalize(this->orientation);
	GameManager::spawnGameObject(new Ball(
		this->shape->getPosition().x - normalizeOrientation.x * size.y, 
		this->shape->getPosition().y - normalizeOrientation.y * size.y, 
		10.f, 
		-normalizeOrientation.x, 
		-normalizeOrientation.y, sf::Color::Magenta));
}