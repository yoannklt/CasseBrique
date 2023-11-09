#pragma once

#include <SFML/System/Vector2.hpp>
#include "GameObject.h"

namespace sf
{
	class RectangleShape;
}

class Ball;

class Canon : GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	Canon(float x, float y, float width, float height);
	~Canon();

	void update(float deltaTime) override;

	// TEST FUNCTIONS
	void launchBall(Ball* ball);


private:
	sf::RectangleShape* rectangle;
	sf::Vector2f orientation;

};