#include "MovingObject.h"
#include <SFML/Graphics.hpp>

MovingObject::MovingObject(float x, float y, float width, float height) : GameObject( x, y, width,height)
{
	
}

MovingObject::~MovingObject()
{
	
}

void MovingObject::update(float deltaTime)
{
	this->position.x += this->direction.x * this->speed * deltaTime;
	this->position.y += this->direction.y * this->speed * deltaTime;

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

void MovingObject::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}
