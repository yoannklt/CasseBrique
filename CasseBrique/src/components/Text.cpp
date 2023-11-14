#include "Text.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Text::Text(const char* text, sf::Vector2f position, const char* font, int size, sf::Color color)
{
	this->font = new sf::Font();
	this->font->loadFromFile(font);

	this->string = new sf::String(text);
	this->text = new sf::Text(*this->string, *this->font, (unsigned int)size);
	this->text->setPosition(position);        
}

void Text::updateText(const char* text)
{
	this->string = new sf::String(text);
	this->text->setString(*this->string);
}

void Text::setTextStyle(std::vector<sf::Text::Style> styles)
{
	for (int i = 0; i < styles.size(); i++)
		this->text->setStyle(styles[i]);
}






