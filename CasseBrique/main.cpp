#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"

int main(int argc, char* argv[])
{
    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    //Création d'un cercle de radius 100
    Ball oCircle(50.0f, 50.0f, 20.0f);
    sf::CircleShape* circle = oCircle.getShape();
    //A la position 0, 0
    circle->setPosition(0.f, 0.f);
    //Et de couleur verte
    circle->setFillColor(sf::Color::Green);


    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
    //A la position 100, 100
    circle->setPosition(100.f, 100.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);

    sf::Clock clock; 
    oWindow.setFramerateLimit(60);

    //GameLoop
    while (oWindow.isOpen())
    {

        sf::Time deltaTime = clock.getElapsedTime(); 
        clock.restart();     

        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE
        oCircle.update(deltaTime.asSeconds());
        oCircle.updateShape();
        std::cout << deltaTime.asSeconds() << std::endl;
        //DRAW
        oWindow.clear();

        oWindow.draw(*circle); 
        oWindow.draw(oRectangle);

        oWindow.display();
    }

    return 0;
}