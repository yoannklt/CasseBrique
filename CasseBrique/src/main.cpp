#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/GameManager.h"
#include "entities/MovingObject.h"
#include "entities/Canon.h"
#include "entities/Brick.h"
#include "engine/events/EventsManager.h"
#include "components/Score.h"
#include "engine/rendering/Window.h"


int main(int argc, char** argv)
{
    //Création d'une fenêtre
    //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "BrickBreaker", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(640, 480), "BrickBreaker", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    Window window(640, 480, "BrickBreaker");
    GameManager::setWindow(&window);
    //GameManager::eventManager.subscribe<GameManager>(CLOSE_WINDOW, &GameManager::getInstance(), &GameManager::getInstance().closeWindow);

    //GameManager::spawnGameObject(new MovingObject(200.f, 200.f, 50.f, 60.f, 1.f, 1.f));
    GameManager::spawnGameObject(new Canon(320.f, 240.f, 50.f, 100.f));
    GameManager::spawnStaticBody(new Brick(10.f, 10.f, 30.f, 460.f)); 
    GameManager::spawnStaticBody(new Brick(600.f, 10.f, 30.f, 460.f)); 
    GameManager::spawnStaticBody(new Brick(50.f, 10.f, 540.f, 30.f)); 
    //GameManager::spawnStaticBody(new Brick(120.f, 70.f, 540.f, 30.f));
    GameManager::spawnStaticBody(new Brick(50.f, 440.f, 540.f, 30.f));

    GameManager::spawnGameObject(new Score("0", {50, 50}, "C:/users/ykerlogot/source/repos/CasseBrique/CasseBrique/src/assets/fonts/Roboto-Regular.ttf", 30, sf::Color::White));



    sf::Clock clock;
    window.getWindow()->setFramerateLimit(60);

    //GameLoop
    while (window.getWindow()->isOpen())
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