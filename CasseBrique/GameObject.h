#pragma once

class GameObject
{
public:
	GameObject(float x, float y, float width, float height);
	~GameObject();

	virtual void update(float deltaTime) {};

	void setPosition(float xpos, float ypos);
	float convertRadiansToDegrees(float radianAngle);

protected:
	float position[2] = { 0.0f, 0.0f };
	float size[2];

private:
};

