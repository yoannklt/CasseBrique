#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    //Création d'une fenêtre
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "BrickBreaker", sf::Style::Fullscreen);

    //Création d'un cercle de radius 100
    sf::CircleShape oCircle(100.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Green);


    //Création d'un rectangle de taille 50, 50
    sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
    //A la position 100, 100
    oCircle.setPosition(100.f, 100.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Blue);

    //GameLoop
    while (window.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();
        }

        //UPDATE

        //DRAW
        window.clear();

        window.draw(oCircle);
        window.draw(oRectangle);

        window.display();
    }

    return 0;
}