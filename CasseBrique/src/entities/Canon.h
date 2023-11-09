#pragma once

#include "GameObject.h"
#include "Ball.h"

class Canon : GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	Canon(float x, float y, float width, float height);
	~Canon();

	// SHAPE RELATED FUNCTIONS
	inline sf::RectangleShape* getShape() { return rectangle; };
	void updateShape(int x, int y);

	// TEST FUNCTIONS
	void launchBall(Ball* ball);


private:
	sf::RectangleShape* rectangle;
	sf::Vector2f orientation;

};