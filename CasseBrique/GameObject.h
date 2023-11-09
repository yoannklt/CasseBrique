#pragma once

#include <SFML/Graphics.hpp>
#include "Maths.h"

using namespace Maths;

class GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	GameObject(float x, float y, float width, float height);
	~GameObject();

	// POSITION RELATED FUNCTIONS
	sf::Vector2f getPosition();
	float getX();
	float getY();
	float getXMax();
	float getYMax();
	float getWidth();
	float getHeight();
	void setPosition(float xpos, float ypos);

	// DIRECTLY OBJECT RELATED FUNCTIONS
	virtual void update(float deltaTime) {};


	// MATHS FUNCTIONS 
	//sf::Vector2f normalizeVect(float x, float y);
	//float convertRadiansToDegrees(float radianAngle);

protected:
	sf::Vector2f position = { 0.0f, 0.0f };
	sf::Vector2f size;

private:
};

