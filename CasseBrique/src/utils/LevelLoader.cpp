#include "LevelLoader.h"
#include "../core/GameManager.h"
#include "../objects/Brick.h"
#include "../objects/Canon.h"

std::unordered_map<std::string, GameObjectTypes> LevelLoader::map = {
	{"Brick", BRICK},
	{"Canon", CANON}
};

void LevelLoader::load(std::string fileName)
{
	std::string line;
	std::string delimiter = "|";
	std::ifstream levelFile("data/levels/" + fileName);

	size_t pos = 0;

	std::vector<std::string> parameters = {};

	if (levelFile.is_open())
	{
		while (std::getline(levelFile, line))
		{
			parameters.clear();
			while ((pos = line.find(delimiter)) != std::string::npos)
			{
				parameters.push_back((line.substr(0, pos)).c_str());
				line.erase(0, pos + delimiter.length()); 
			} 

			switch (LevelLoader::map[parameters[0]])
			{
			case BRICK:
				GameManager::spawnStaticBody(new Brick(std::stof(parameters[1]), std::stof(parameters[2]), std::stof(parameters[3]), std::stof(parameters[4]))); 
				break;

			case CANON:
				GameManager::spawnGameObject(new Canon(std::stof(parameters[1]), std::stof(parameters[2]), std::stof(parameters[3]), std::stof(parameters[4]))); 
				break;

			default:
				break;
			}
		}
		levelFile.close();
	}
	else
		std::cout << "FAILED TO LOAD THE FILE";
}
