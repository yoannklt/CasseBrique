#include "Collisions.h"
#include "../entities/GameObject.h"


Collisions::Collisions() 
{

}

Collisions::~Collisions()
{
}

void Collisions::checkAABBCollision(GameObject* objects[2])
{
	bool longestWidthIndex = objects[0]->getWidth() < objects[1]->getWidth();
	bool longestHeightIndex = objects[0]->getHeight() < objects[1]->getHeight();

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
		int a = 0;
	}
}

void Collisions::checkCollisions()
{
	for (int i = 0; i < this->rigidBodies.size(); ++i) {
		GameObject* rigidBody = rigidBodies[i];
		for (int j = 0; j < this->staticBodies.size(); ++j) {
			GameObject* objects[2] = { rigidBody, staticBodies[j] };
			checkAABBCollision(objects);
		}
		
	}
}
