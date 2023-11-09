#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"
#include "Ball.h"
#include "Canon.h"


int main(int argc, char* argv[])
{
    sf::Mouse mouse;

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML"); 


    //Création d'un cercle de radius 10
    Ball oCircle(320.0f, 10.0f, 10.0f); 

    sf::CircleShape* circle = oCircle.getShape();

  
    Brick oBrick(50.0f, 50.0f, 150.0f, 40.0f);

    //Et de couleur verte
    circle->setFillColor(sf::Color::Green);

    Canon oCanon(320.0f, 480.0f, 50.0f, 100.0f); 

    //Création d'un canon de taille 50, 50
    sf::RectangleShape* brick = oBrick.getShape();
    sf::RectangleShape* canon = oCanon.getShape();;  
 
    //Et de couleur rouge
    canon->setFillColor(sf::Color::Red);
    brick->setFillColor(sf::Color::Magenta);

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
            switch (oEvent.type)
            {
            case sf::Event::Closed:
                oWindow.close();
                break;

            case sf::Event::MouseButtonPressed:
                switch (oEvent.mouseButton.button)
                {
                case sf::Mouse::Left:
                    oCanon.launchBall(&oCircle);
                    //std::cout << "Left mouse button pressed";
                    break;
                }
            }

                
        }

        //UPDATE
        oCircle.update(deltaTime.asSeconds());
        //std::cout << "X: " << circle->getPosition().x << " Y: " << circle->getPosition().y << std::endl;
        
        oCircle.updateShape();
        oCanon.updateShape(mousePos.x, mousePos.y);
        //DRAW
        oWindow.clear();
        oWindow.draw(*brick);
        oWindow.draw(*circle); 
            
        oWindow.draw(*canon);

        oWindow.display();
    }

    return 0;
}