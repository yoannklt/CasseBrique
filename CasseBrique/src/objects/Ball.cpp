#include "Ball.h"
#include <SFML/Graphics.hpp>
#include "../core/GameManager.h"
#include "../engine/rendering/Window.h"
#include "../engine/events/EventsManager.h"

Ball::Ball(float x, float y, float diameter, float orientationX, float orientationY) : MovingObject(x, y, diameter, diameter, orientationX, orientationY)
{
	this->shape = new sf::CircleShape(diameter / 2);
	this->drawable = this->shape;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->transformable = this->shape;  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->transformable->setOrigin(diameter/2, diameter/2);
	this->setPosition(x - this->transformable->getOrigin().x, y - this->transformable->getOrigin().y);	
}

Ball::Ball(float x, float y, float radius, float orientationX, float orientationY, sf::Color color) : Ball(x,  y,  radius, orientationX, orientationY)
{
	this->shape->setFillColor(color);
}

Ball::~Ball()
{
	GameManager::eventManager.trigger(BALL_DESTROYED);
	delete this->shape;
}

void Ball::bounce(int side)
{
	float orientationTab[2] = { orientation.x, orientation.y };
	orientationTab[side] = -orientationTab[side];
	this->orientation.x = orientationTab[0];
	this->orientation.y = orientationTab[1];
}

void Ball::update(float deltaTime)
{
	
	if (position.x + size.x >= GameManager::getWindow()->getSFMLObject()->getSize().x or position.x <= 0)
	{
		orientation.x = -orientation.x;
	}

	if (position.y <= 0)
	{
		orientation.y = -orientation.y;
	} 

	MovingObject::update(deltaTime);

	if (position.y >= GameManager::getWindow()->getSFMLObject()->getSize().y) {
		GameManager::killGameObject(this);
	}

}

void Ball::onCollision(sf::Vector2f collisionSide) {
	this->bounce(collisionSide.x);
}

