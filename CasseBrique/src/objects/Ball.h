#pragma once

#include "MovingObject.h"

namespace sf
{
	class Color;
	class CircleShape;
}


class Ball : public MovingObject
{
public:
	Ball(float x, float y, float radius, float orientationX, float orientationY);
	Ball(float x, float y, float radius, float orientationX, float orientationY, sf::Color color);
	~Ball() override;

	void update(float deltaTime) override;
	void onCollision(sf::Vector2f collisionSide) override;
	void bounce(int side);

protected:
	sf::CircleShape* shape;

private:
};