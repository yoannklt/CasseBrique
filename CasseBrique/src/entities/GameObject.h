#pragma once

#include <SFML/Graphics.hpp>

typedef struct VectorDirection {

};

class GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	GameObject(float x, float y, float width, float height);
	~GameObject();

	//
	virtual void update(float deltaTime) {};

	// GETTERS/SETTERS
	sf::Vector2f getPosition();
	void setPosition(float xPos, float yPos);
	float getX();
	float getY();
	float getXMax();
	float getYMax();
	float getWidth();
	float getHeight();
	

	//to move to math namespace
	float convertRadiansToDegrees(float radianAngle);

protected:
	
	sf::Shape* shape;
	sf::Vector2f position;
	sf::Vector2f size;

private:
};