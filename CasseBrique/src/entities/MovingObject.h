#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(float x, float y, float width, float height, float directionX, float directionY);
	~MovingObject();

	virtual void update(float deltaTime) override;

	void setDirection(float directionX, float directionY);


protected:
	sf::Vector2f direction;
	int speed = 500;

private:
	
};