#pragma once

#include <vector>

class CollisionsSystem
{
public:
	CollisionsSystem();
	~CollisionsSystem();
	void checkCollisions();
	void checkAABBCollisions();
private:
	std::vector<GameObject*> staticBodies;
	std::vector<GameObject*> rigidBodies;
}