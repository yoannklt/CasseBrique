#include <SFML/Graphics.hpp>
#include "core/GameManager.h"
#include "entities/MovingObject.h"
#include "entities/Canon.h"
#include "entities/Brick.h"
#include "engine/events/EventsManager.h"
#include "components/Score.h"
#include "engine/rendering/Window.h"
#include "engine/textures/TextureManager.h"


int main(int argc, char** argv)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
     
    //Création d'une fenêtre
    Window window(700, 480, "BrickBreaker");
    GameManager::setWindow(&window);

    GameManager::loadLevel("levelOne.txt");
    GameManager::spawnGameObject(new Score("Score: 0", { 50, 50 }, "assets/fonts/Roboto-Regular.ttf", 40, sf::Color::White));

    sf::Clock clock;
    window.getWindow()->setFramerateLimit(60);

    //GameLoop
    while (window.getWindow()->isOpen())
    {
        sf::Time deltaTime = clock.getElapsedTime();
        clock.restart();

        //UPDATE
        GameManager::update(deltaTime.asSeconds());

        //DISPLAY
        GameManager::render();

    }

    TextureManager::destroyTexture(); 

    return 0;
}