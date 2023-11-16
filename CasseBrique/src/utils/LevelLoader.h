#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

enum GameObjectTypes
{
	BRICK = 0,
	CANON,
	GAME_OBJECT_TYPES_COUNT
};


class LevelLoader
{
public:
	static void load(std::string fileName);  

private:
	static std::unordered_map<std::string, GameObjectTypes> map;
};   

