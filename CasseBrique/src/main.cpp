#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/GameManager.h"
#include "entities/MovingObject.h"
#include "entities/Canon.h"

int main(int argc, char** argv)
{
    //Cr�ation d'une fen�tre
    //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "BrickBreaker", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(640, 480), "BrickBreaker", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    GameManager::setWindow(&window);

    //GameManager::spawnGameObject(new MovingObject(200.f, 200.f, 50.f, 60.f, 1.f, 1.f));
    GameManager::spawnGameObject(new Canon(320.f, 480.f, 50.f, 100.f));

    sf::Clock clock;
    window.setFramerateLimit(60);

    //GameLoop
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.getElapsedTime();
        clock.restart();

        //EVENT
        /*sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            switch (oEvent.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                switch (oEvent.mouseButton.button)
                {
                case sf::Mouse::Left:
                    std::cout << "Left click detected" << std::endl;
                    break;

                default:
                    break;
                }

            default:
                break;
            }
        }*/

        //UPDATE
        GameManager::update(deltaTime.asSeconds());

        //DISPLAY
        GameManager::render();
    }

    return 0;
}