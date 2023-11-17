#include "core/GameManager.h"
#include "engine/rendering/Window.h"

int main(int argc, char** argv)
{
    Window window(640, 480, "BrickBreaker");
    GameManager::bindWindow(&window);
    GameManager::InitBrickBreaker();

    //GameLoop
    while (window.getSFMLObject()->isOpen())
    {
        //UPDATE
        GameManager::update();

        //DISPLAY
        GameManager::render();
    }

    return 0;
}