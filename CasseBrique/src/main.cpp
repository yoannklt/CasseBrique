#include <SFML/Graphics.hpp>
#include "core/GameManager.h"
#include "entities/MovingObject.h"

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "BrickBreaker", sf::Style::Fullscreen);
    GameManager gameManager(&window);
    gameManager.spawnGameObject(new MovingObject(200.f, 200.f, 50.f, 60.f));

    sf::Clock clock;
    window.setFramerateLimit(60);

    //GameLoop
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.getElapsedTime();
        clock.restart();

        //EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();
        }

        //UPDATE
        gameManager.update(deltaTime.asSeconds());

        //DISPLAY
        gameManager.render();
    }

    return 0;
}