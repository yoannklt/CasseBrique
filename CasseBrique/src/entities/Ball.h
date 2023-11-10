#pragma once

#include "MovingObject.h"

namespace sf
{
	class Color;
}

class Ball : public MovingObject
{
public:
	Ball(float x, float y, float radius);
	Ball(float x, float y, float radius, float directionX, float directionY);
	Ball(float x, float y, float radius, float directionX, float directionY, sf::Color color);
	~Ball();

	void update(float deltaTime) override;

	void bounce(int side);

private:
};