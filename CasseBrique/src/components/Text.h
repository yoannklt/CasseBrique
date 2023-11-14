#pragma once

#include <SFML/System/Vector2.hpp>
#include "SFML/Graphics/Text.hpp"

namespace sf
{
	class Font;
	class String;
	class Color;
}

class Text
{
public:
	Text(const char* text, sf::Vector2f position, const char* font, int size, sf::Color color);
	~Text() {};

	void updateText(const char* text); 
	void setTextStyle(std::vector<sf::Text::Style> styles);
	inline sf::Text* getText() { return text; }

private:
	sf::Font* font;
	sf::String* string;
	sf::Text* text;
}; 
