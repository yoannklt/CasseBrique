#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
{
	this->position[0] = x;
	this->position[1] = y;
	this->size[0] = width;
	this->size[1] = height;
}

GameObject::~GameObject()
{
	delete this->shape;
}

void GameObject::setPosition(float xpos, float ypos)
{
	this->position[0] = xpos;
	this->position[1] = ypos;
}

float* GameObject::getPosition() {
	return this->position;
}

float GameObject::getX() {
	return this->position[0];
}
float GameObject::getY() {
	return this->position[1];
}
float GameObject::getXMax() {
	return this->position[0] + this->size[0];
}

float GameObject::getYMax() {
	return this->position[1] + this->size[1];
}
float GameObject::getWidth() {
	return this->size[0];
}
float GameObject::getHeight() {
	return this->size[1];
}

float GameObject::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14;
	return degreeAngle;
}