#include "Maths.h"
#include <corecrt_math.h>

sf::Vector2f Maths::normalize(sf::Vector2f vector)
{
	float norm = sqrtf(powf(vector.x, 2) + powf(vector.y, 2));
	sf::Vector2f normalizedVector = { vector.x / norm, vector.y / norm };
	return normalizedVector; 
}

float Maths::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14159265358979323846;
	return degreeAngle; 
}

