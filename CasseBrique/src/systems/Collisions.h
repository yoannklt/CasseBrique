#pragma once

#include <vector>

class GameObject;
class MovingObject;

class Collisions
{
public:
	Collisions();
	~Collisions();
	void checkCollisions();
	void checkAABBCollision(MovingObject* movingObject, GameObject* gameObject);
private:
	std::vector<GameObject*> staticBodies;
	std::vector<MovingObject*> rigidBodies;
};