#include "MovingObject.h"
#include <SFML/Graphics.hpp>

MovingObject::MovingObject(float x, float y, float width, float height) : GameObject( x, y, width,height)
{
	this->rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangle->setPosition(x, y);
}

MovingObject::~MovingObject()
{
}

void MovingObject::update(float deltaTime)
{
	this->position[0] += this->direction[0] * this->speed * deltaTime;
	this->position[1] += this->direction[1] * this->speed * deltaTime;

}

bool MovingObject::checkAABBCollision(GameObject* object)
{
	GameObject* objects[2] = {this, object};
	bool longestWidthIndex = this->getWidth() < object->getWidth();
	bool longestHeightIndex = this->getHeight() < object->getHeight();

	GameObject* longWidthObject = objects[longestWidthIndex];
	GameObject* longHeightObject = objects[longestHeightIndex];
	GameObject* shortWidthObject = objects[!longestHeightIndex];
	GameObject* shortHeightObject = objects[!longestHeightIndex];

	if ((longWidthObject->getX() < shortWidthObject->getX() && shortWidthObject->getX() < longWidthObject->getXMax()
		||
		(longWidthObject->getX() < shortWidthObject->getXMax() && shortWidthObject->getXMax() < longWidthObject->getXMax()))
		&&
		((longHeightObject->getX() < shortHeightObject->getX() && shortHeightObject->getX() < longHeightObject->getXMax())
		||
		(longHeightObject->getX() < shortHeightObject->getXMax() && shortHeightObject->getXMax() < longHeightObject->getXMax())))
	{
		return true;
	}
	return false;
}