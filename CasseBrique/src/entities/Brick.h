#pragma once

#include <SFML/Config.hpp>
#include "GameObject.h"

namespace sf
{
	class RectangleShape;
	class Color;
	class Sprite;
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
	int health = 4;
	int maxHealth = health;
	sf::Color* color;
	sf::Uint8* colorValue;
	sf::Sprite* sprite;
	int imageKey;
};