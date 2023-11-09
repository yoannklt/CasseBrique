#include "Maths.h"
#include <corecrt_math.h>


/// <param name="startPointX :"> The first point's X coordinate in the plan</param>
/// <param name="startPointY :"> The first point's Y coordinate in the plan</param>
/// <param name="endPointX :"> The second point's X coordinate in the plan</param>
/// <param name="endPointY :" > The second point's Y coordinate in the plan</param>
/// <returns>A sf::Vector2f with x and y coordinates</returns>
sf::Vector2f Maths::vect(float startPointX, float startPointY, float endPointX, float endPointY)
{
	sf::Vector2f vector = { endPointX - startPointX, endPointY - startPointY };

	return vector;
}

float Maths::getNorm(sf::Vector2f vector)
{
	float norm = sqrtf(powf(vector.x, 2) + powf(vector.y, 2));

	return norm;
}

sf::Vector2f Maths::normalize(sf::Vector2f vector)
{
	float norm = getNorm(vector);
	sf::Vector2f normalizedVector = { vector.x / norm, vector.y / norm };
	return normalizedVector; 
}

float Maths::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14159265358979323846;
	return degreeAngle; 
}

