#include "Score.h"
#include "../core/GameManager.h"
#include "../engine/events/EventsManager.h"
#include <iostream>

Score::Score(const char* text, sf::Vector2f position, const char* font, int size, sf::Color color) : Text(text, position, font, size, color)
{
	GameManager::eventManager.subscribe<Score>(BRICK_DESTROY, this, &Score::incrementScoreOnBrickDestroyed);
	GameManager::eventManager.subscribe<Score>(BRICK_TOUCH, this, &Score::incrementScoreOnBrickTouched);

}

int Score::incrementScoreOnBrickDestroyed()
{
	this->score += 40;
	this->updateText(std::to_string(this->score));

	return 0;
}

int Score::incrementScoreOnBrickTouched()
{
	this->score += 10;
	this->updateText(std::to_string(this->score));

	return 0;
}