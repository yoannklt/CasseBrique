#pragma once

#include <SFML/System/Vector2.hpp>
#include "GameObject.h"

namespace sf
{
	class Color;
	class RectangleShape;
}     

class Ball;

class Canon : public GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	Canon(float x, float y, float width, float height);
	Canon(float x, float y, float width, float height, sf::Color color);
	~Canon();

	void update(float deltaTime) override;

	// TEST FUNCTIONS
	int launchBall();
	inline int toggleShootCondition() { this->canShoot = !this->canShoot; return 0; };

protected:
	sf::RectangleShape* shape;

private:
	sf::Vector2f orientation;
	bool canShoot = true;
};