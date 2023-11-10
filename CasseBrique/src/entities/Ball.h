#pragma once

#include "MovingObject.h"


class Ball : public MovingObject
{
public:
	Ball(float x, float y, float radius, float directionX, float directionY);
	~Ball();

	void update(float deltaTime) override;

	void bounce(int side);

private:
};