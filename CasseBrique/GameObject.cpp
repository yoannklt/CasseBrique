#include "GameObject.h"
#include <cmath>

GameObject::GameObject(float x, float y, float width, float height)
{
	this->position.x = x;
	this->position.y = y;
	this->size.x = width;
	this->size.y = height;
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(float xpos, float ypos)
{
	this->position.x = xpos;
	this->position.y = ypos;
}

sf::Vector2f GameObject::getPosition() {
	return this->position;
}

float GameObject::getX() {
	return this->position.x;
}

float GameObject::getY() {
	return this->position.y;
}

float GameObject::getXMax() {
	return this->position.x + this->size.x;
}

float GameObject::getYMax() {
	return this->position.y + this->size.y;
}

float GameObject::getWidth() {
	return this->size.x;
}

float GameObject::getHeight() {
	return this->size.y;
}

sf::Vector2f GameObject::normalizeVect(float x, float y)
{
	float norme = sqrtf(powf(x, 2) + powf(y, 2));
	sf::Vector2f normalizedVector = { x / norme, y / norme };
	return normalizedVector;
}

float GameObject::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14159265358979323846;
	return degreeAngle;
}
