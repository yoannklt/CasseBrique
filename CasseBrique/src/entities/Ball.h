#pragma once

#include "MovingObject.h"

namespace sf
{
	class CircleShape;
}

class Ball : public MovingObject
{
public:
	Ball(float x, float y, float radius, float directionX, float directionY);
	~Ball();

	void update(float deltaTime) override;

	void bounce(int side);

private:
	sf::CircleShape* circle;
};