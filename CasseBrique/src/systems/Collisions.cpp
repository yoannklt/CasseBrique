#include "Collisions.h"
#include "../entities/GameObject.h"
#include "../entities/MovingObject.h"

Collisions::Collisions() 
{

}

Collisions::~Collisions()
{
}

void Collisions::checkAABBCollision(MovingObject* movingObject, GameObject* gameObject)
{
	bool longestWidthIndex = movingObject->getWidth() < gameObject->getWidth();
	bool longestHeightIndex = movingObject->getHeight() < gameObject->getHeight();

	GameObject* longWidthObject = longestWidthIndex ? gameObject : movingObject;
	GameObject* longHeightObject = longestHeightIndex ? gameObject : movingObject;
	GameObject* shortWidthObject = !longestWidthIndex ? gameObject : movingObject;
	GameObject* shortHeightObject = !longestHeightIndex ? gameObject : movingObject;

	if ((longWidthObject->getX() < shortWidthObject->getX() && shortWidthObject->getX() < longWidthObject->getXMax()
		||
		(longWidthObject->getX() < shortWidthObject->getXMax() && shortWidthObject->getXMax() < longWidthObject->getXMax()))
		&&
		((longHeightObject->getX() < shortHeightObject->getX() && shortHeightObject->getX() < longHeightObject->getXMax())
			||
			(longHeightObject->getX() < shortHeightObject->getXMax() && shortHeightObject->getXMax() < longHeightObject->getXMax())))
	{
		sf::Vector2f movingObjectOrientation = movingObject->getOrientation();
		float xVerticalSide = isRight * getX() + isLeft * getXMax(); //soit x = getX(); soit x = getXMax; (xVerticalSide, y), (xVerticalSide, yMax);
		float yHorizontalSize = isDown * getY() + isUp * getYMax();
		pPrimeX = xVerticalSide;
		deltaMove = p/ movingObjectOrientation.x
	}
}




void Collisions::checkCollisions()
{
	for (int i = 0; i < this->rigidBodies.size(); ++i) {
		MovingObject* rigidBody = rigidBodies[i];
		for (int j = 0; j < this->staticBodies.size(); ++j) {
			checkAABBCollision(rigidBody, staticBodies[j]);
		}
	}
}
