#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

class GameObject;
class MovingObject;

struct CollisionData {
	sf::Vector2f collisionSide;
	float overMoveCoefficient;
};

class Collisions
{
public:
	Collisions();
	~Collisions();
	void registerStaticBody(GameObject* staticBody);
	void registerRigidBody(MovingObject* rigidBody);
	void unregisterStaticBody(GameObject* staticBody);
	void unregisterRigidBody(MovingObject* rigidBody);
	void checkCollisions();
	CollisionData checkAABBCollision(MovingObject* movingObject, GameObject* gameObject);
private:
	std::vector<GameObject*> staticBodies;
	std::vector<MovingObject*> rigidBodies;
};