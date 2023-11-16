#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/GameManager.h"
#include "entities/MovingObject.h"
#include "entities/Canon.h"
#include "entities/Brick.h"
#include "engine/events/EventsManager.h"
#include "components/Score.h"
#include "engine/rendering/Window.h"
#include "engine/textures/TextureManager.h"
#include <cstdlib>
#include <ctime>


int main(int argc, char** argv)
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    //Création d'une fenêtre
    Window window(700, 480, "BrickBreaker");
    GameManager::setWindow(&window);

    GameManager::spawnGameObject(new Score("0", {50, 50}, "assets/fonts/Roboto-Regular.ttf", 30, sf::Color::White));
    GameManager::loadLevel("levelOne.txt");

    sf::Clock clock;
    window.getWindow()->setFramerateLimit(60);

    //GameLoop
    while (window.getWindow()->isOpen())
    {
        sf::Time deltaTime = clock.getElapsedTime();
        clock.restart();

        //EVENT

        //UPDATE
        GameManager::update(deltaTime.asSeconds());

        //DISPLAY
        GameManager::render();

    }

    TextureManager::destroyTexture(); 

    return 0;
}