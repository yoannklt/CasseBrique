#pragma once

#include "GameObject.h"

namespace sf
{
	class RectangleShape;
}


class Brick : GameObject
{
public:
	Brick(float x, float y, float width, float height);
	~Brick();

	void update(float deltaTime) override;


private:
};