#pragma once

#include <SFML/System/Vector2.hpp>

namespace sf 
{
	class Shape;
}

class GameObject
{
public:
	// CONSTRUCTORS / DESTRUCTORS
	GameObject(float x, float y, float width, float height);
	~GameObject();

	//
	virtual void update(float deltaTime) {};

	// GETTERS/SETTERS
	virtual void onCollision(sf::Vector2f collisionSide) {};
	sf::Vector2f getPosition();
	void setPosition(float xpos, float ypos);
	float getX();
	float getY();
	float getXMax();
	float getYMax();
	float getWidth();
	inline float getHeight() 
	{
		return this->size.y;
	}
	sf::Shape* getShape();
	
	void setId(int id) { this->id = id; };

	//to move to math namespace
	float convertRadiansToDegrees(float radianAngle);

protected:
	
	sf::Shape* shape;
	sf::Vector2f position;
	sf::Vector2f size;
	int id;

private:
};