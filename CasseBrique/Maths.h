#pragma once

#include <SFML/System/Vector2.hpp>

namespace Maths
{
	sf::Vector2f vect(float startPointX, float startPointY, float endPointX, float endPointY);

	float getNorm(sf::Vector2f vector);
	sf::Vector2f normalize(sf::Vector2f vector);
	float convertRadiansToDegrees(float radianAngle);

}