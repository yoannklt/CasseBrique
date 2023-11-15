#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(float x, float y, float width, float height, float orientationX, float orientationY);
	~MovingObject() override {};

	virtual void update(float deltaTime) override;
	virtual void onCollision(sf::Vector2f collisionSide) override {};

	inline sf::Vector2f getOrientation() { return orientation; };
	inline void setOrientation(float orientationX, float orientationY) { orientation = { orientationX, orientationY }; };

protected:
	sf::Vector2f orientation;
	int speed = 500;

private:
	
};