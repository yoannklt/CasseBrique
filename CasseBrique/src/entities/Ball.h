#pragma once

#include "MovingObject.h"



class Ball : public MovingObject
{
public:
	Ball(float x, float y, float diameter, float directionX, float directionY);
	~Ball();

	void update(float deltaTime) override;
	void onCollision(sf::Vector2f collisionSide) override;
	void bounce(int side);

private:
};