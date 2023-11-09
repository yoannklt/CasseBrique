#pragma once

#include <vector>

#include <vector>

class GameObject;

class Collisions
{
public:
	Collisions();
	~Collisions();
	void checkCollisions();
	void checkAABBCollision(GameObject* objects[2]);
private:
	std::vector<GameObject*> staticBodies;
	std::vector<GameObject*> rigidBodies;
};