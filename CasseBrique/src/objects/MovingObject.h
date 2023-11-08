#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class MovingObject : public GameObject
{
public:
	MovingObject(float x, float y, float width, float height);
	~MovingObject();

	virtual void update(float deltaTime) override;
	bool checkAABBCollision(GameObject* object);

	sf::RectangleShape* rectangle;
protected:
	float direction[2] = { 1.0f, 0.1f };

private:
	int speed = 150;
};