#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(float x, float y, float width, float height);
	~MovingObject();

	void update(float deltaTime) override;


private:
	float direction[2] = { 1.0f, 0.0f };
	int speed = 5;
};

