#include "Collisions.h"
#include "../entities/GameObject.h"
#include "../entities/MovingObject.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>

Collisions::Collisions() 
{

}

Collisions::~Collisions()
{
}

void Collisions::registerStaticBody(GameObject* staticBody) {
	this->staticBodies.push_back(staticBody);
}

void Collisions::registerRigidBody(MovingObject* rigidBody) {
	this->rigidBodies.push_back(rigidBody);
}

void Collisions::unregisterStaticBody(GameObject* staticBody)
{
	this->staticBodies.erase(std::remove(this->staticBodies.begin(), this->staticBodies.end(), staticBody), this->staticBodies.end());
}

void Collisions::unregisterRigidBody(MovingObject* rigidBody)
{
	this->rigidBodies.erase(std::remove(this->rigidBodies.begin(), this->rigidBodies.end(), rigidBody), this->rigidBodies.end());
}

CollisionData Collisions::checkAABBCollision(MovingObject* movingObject, GameObject* staticObject)
{

	/*
	// checks if there is a collision
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
	{ */

	// checks if there is no collision and then takes the inverse as condition
	if( !(movingObject->getXMax() < staticObject->getX() || movingObject->getX() > staticObject-> getXMax()
		||
		movingObject->getYMax() < staticObject->getY() || movingObject->getY() > staticObject->getYMax()) ) {

		float movingOrientationX = movingObject->getOrientation().x;
		float movingOrientationY = movingObject->getOrientation().y;

		//check if it was a vertical or horizontal collision first
		float movingX = movingObject->getX() * (movingOrientationX < 0) + movingObject->getXMax() * (movingOrientationX > 0);
		float movingY = movingObject->getY() * (movingOrientationY < 0) + movingObject->getYMax() * (movingOrientationY > 0);
		
		float staticX = staticObject->getX() * (movingOrientationX > 0) + staticObject->getXMax() * (movingOrientationX < 0);
		float staticY = staticObject->getY() * (movingOrientationY > 0) + staticObject->getYMax() * (movingOrientationY < 0);

		float moveCoefficient = (movingX - staticX) / movingOrientationX; //moveCoefficient is equivalent to speed * dt in new pos calculation (MovingObject)
		float newPosY = movingOrientationY * moveCoefficient + staticY;
		if (
			((newPosY > movingY) && (movingOrientationY < 0)) 
			|| 
			((newPosY < movingY) && (movingOrientationY > 0))
		) {
			//vertical collision
			return { sf::Vector2f(0.f, 1.f), moveCoefficient };
		}
		else {
			//horizontal collision
			return { sf::Vector2f(1.f, 0.f), (movingY - staticY) / movingOrientationY };
		}
	}
	return { sf::Vector2f(0.f, 0.f), 2000.f }; // second value should be replaced with the physical step + 1 (so that it's an impossible step)
}




void Collisions::checkCollisions()
{
	for (int i = 0; i < this->rigidBodies.size(); ++i) {
		MovingObject* rigidBody = rigidBodies[i];
		for (int j = 0; j < this->staticBodies.size(); ++j) {
			GameObject* staticBody = staticBodies[j];
			CollisionData collisionData = checkAABBCollision(rigidBody, staticBody);
			if (collisionData.overMoveCoefficient != 2000) { //means no colisions were detected
				
				rigidBody->onCollision(collisionData.collisionSide); //triggerEvent on Specific
				rigidBody->setPosition( //fixing the moving object position out of the object it collided with
					collisionData.overMoveCoefficient * rigidBody->getOrientation().x + rigidBody->getPosition().x,
					collisionData.overMoveCoefficient * rigidBody->getOrientation().y + rigidBody->getPosition().y
				);
				staticBody->onCollision(collisionData.collisionSide);
			}
		}
	}
}
