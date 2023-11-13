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
	~Brick();

	void update(float deltaTime) override;
	void onCollision(sf::Vector2f collisionSide) override;


private:
	int health = 5;
};