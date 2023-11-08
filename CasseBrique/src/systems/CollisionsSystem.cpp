#include "CollisionsSystem.h"

void CollisionsSystem::checkCollisions()
{
	for (int i = 0; i < this->rigidBodies.size(); ++i) {
		for (int i = 0; i < this->staticBodies; ++i)
		checkAABBCollision(rigidBodies[i])
	}
}
