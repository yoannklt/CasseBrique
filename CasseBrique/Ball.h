#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"


class Ball : public MovingObject
{
public:
	Ball(float x, float y, float radius);
	~Ball();
	inline sf::CircleShape* getShape() { return circle; };
	void updateShape();

private:
	sf::CircleShape* circle;
};

