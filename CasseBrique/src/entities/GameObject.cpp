#include "GameObject.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>$
#include <iostream>

class B {
public:
	int foo()
	{
		std::cout << "foo" << std::endl;
		return 0;
	}
};

class VoidClass{};

GameObject::GameObject(float x, float y, float width, float height)
{
	float(GameObject::*methodPointerA)() =  &GameObject::methodName;
	int(B:: * methodPointerB)() = &B::foo;
	float(GameObject::*methodPointerC)() =  &GameObject::methodNameTwo;
	float(GameObject::*methodPointerD)() =  &GameObject::methodName;

	void(VoidClass:: * a)() = (void(VoidClass::*)()) methodPointerA;
	void(VoidClass:: * b)() = (void(VoidClass::*)()) methodPointerB;
	void(VoidClass:: * c)() = (void(VoidClass::*)()) methodPointerC;
	void(VoidClass:: * d)() = (void(VoidClass::*)()) methodPointerD;



	system("cls");
	std::cout << "GameObject::methodName == B::foo - " << ((a == b) ? "Same Pointer" : "Different Pointer") << std::endl;
	std::cout << "GameObject::methodName == GameObject::methodName - " << ((a == d) ? "Same Pointer" : "Different Pointer") << std::endl;
	std::cout << "GameObject::methodName == GameObject::methodNameTwo - " << ((a == c) ? "Same Pointer" : "Different Pointer") << std::endl;



	this->position.x = x;
	this->position.y = y;
	this->size.x = width;
	this->size.y = height;
}

float GameObject::methodName() {
	return 0.f;
}

float GameObject::methodNameTwo() {
	return 0.f;
}

GameObject::~GameObject()
{
	delete this->shape;
}

sf::Shape* GameObject::getShape() {
	return this->shape;
}

void GameObject::setPosition(float xpos, float ypos)
{
	this->position.x = xpos;
	this->position.y = ypos;
	this->shape->setPosition(xpos, xpos);
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
/*
float GameObject::getHeight() {
	return this->size.y;
}
*/

float GameObject::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14;
	return degreeAngle;
}