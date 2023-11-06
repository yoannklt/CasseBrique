#pragma once

class GameObject;

class AbstractGameManager {

public:
	AbstractGameManager() {};
	~AbstractGameManager() {};
	virtual void render() = 0;
	virtual void update() = 0;

private:
	GameObject** gameObjects = {};
	GameObject** renderObjects = {};
	GameObject** updateObjects = {};
};

