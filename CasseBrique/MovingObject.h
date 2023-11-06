#pragma once
#include "GameObject.h"

class MovingObject : GameObject
{
public:
	MovingObject(float x, float y, float width, float height);
	~MovingObject();

	void update(float deltaTime) override;

private:
	float direction[2] = { 0.0f, 0.0f };
	int speed = 0;
};

