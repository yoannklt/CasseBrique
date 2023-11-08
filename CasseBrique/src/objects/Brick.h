#pragma once

#include "SFML/Graphics.hpp"
#include "GameObject.h"

class Brick : GameObject
{
public:
	Brick(float x, float y, float width, float height);
	~Brick();

	inline sf::RectangleShape* getShape() { return rectangle; };
	void updateShape(int x, int y);


private:
	sf::RectangleShape* rectangle;

};