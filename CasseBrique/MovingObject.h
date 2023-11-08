#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	MovingObject(float x, float y, float width, float height);
	~MovingObject();

	// DIRECTLY OBJECT RELATED FUNCTIONS 
	virtual void update(float deltaTime) override;
	bool checkAABBCollision(GameObject* object);

	// VECTOR RELATED FUNCTIONS 
	void setDirection(float x, float y);
	inline sf::Vector2f getDirection() { return direction; };


protected:
	sf::Vector2f direction = { 1.0f, 0.1f }; 

private:
	int speed = 250;
};

