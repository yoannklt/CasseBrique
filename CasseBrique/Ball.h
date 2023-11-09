#pragma once

#include "MovingObject.h"


class Ball : public MovingObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	Ball(float x, float y, float radius);
	~Ball();

	// DIRECTLY OBJECT RELATED FUNCTIONS
	void update(float deltaTime) override;
	void updateShape(); 
	void bounce(int side);

	// SHAPE RELATED FUNCTIONS 
	inline sf::CircleShape* getShape() { return circle; };

private:
	sf::CircleShape* circle;
};

