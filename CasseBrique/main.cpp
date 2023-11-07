#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Brick.h"


int main(int argc, char* argv[])
{
    sf::Mouse mouse;

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");


    //Création d'un cercle de radius 10
    Ball oCircle(320.0f, 0.0f, 10.0f);

    sf::CircleShape* circle = oCircle.getShape();

  
    //Et de couleur verte
    circle->setFillColor(sf::Color::Green);

    Brick oBrick(320.0f, 480.0f, 50.0f, 100.0f); 

    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape* rectangle = oBrick.getShape();;  
 
    //Et de couleur rouge
    rectangle->setFillColor(sf::Color::Red);

    sf::Clock clock; 
    oWindow.setFramerateLimit(60);

    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2i mousePos = mouse.getPosition(oWindow);  
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
        std::cout << "X: " << circle->getPosition().x << " Y: " << circle->getPosition().y << std::endl;
        
        oCircle.updateShape();
        oBrick.updateShape(mousePos.x, mousePos.y);
        //DRAW
        oWindow.clear();
        oWindow.draw(*circle); 
        oWindow.draw(*rectangle);

        oWindow.display();
    }

    return 0;
}