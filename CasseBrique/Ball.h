#pragma once
#include <SFML/Graphics.hpp>
#include "MovingObject.h"


class Ball : MovingObject
{
public:
	Ball(float x, float y, float radius);
	~Ball();
	inline sf::CircleShape* getShape() { return circle; };

private:
	sf::CircleShape* circle;
};

