#pragma once

#include "GameObject.h"

namespace sf
{
	class RectangleShape;
}

class Brick : public GameObject
{
public:
	Brick(float x, float y, float width, float height);
	~Brick() override;

	void update(float deltaTime) override;
	void onCollision(sf::Vector2f collisionSide) override;

	sf::RectangleShape* shape;

private:
	int health = 5;
};