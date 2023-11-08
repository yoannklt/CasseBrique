#pragma once

class GameObject
{
public:
	GameObject(float x, float y, float width, float height);
	~GameObject();

	virtual void update(float deltaTime) {};

	void setPosition(float xpos, float ypos);
	float convertRadiansToDegrees(float radianAngle);
	float* getPosition();
	float getX();
	float getY();
	float getXMax();
	float getYMax();
	float getWidth();
	float getHeight();



protected:
	float position[2] = { 0.0f, 0.0f };
	float size[2];

private:
};