#include <SFML/Graphics.hpp>
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

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE

        //DRAW
        oWindow.clear();

        oWindow.draw(*circle); 
        oWindow.draw(oRectangle);

        oWindow.display();
    }

    return 0;
}