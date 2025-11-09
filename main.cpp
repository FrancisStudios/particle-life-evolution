/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include <SFML/Graphics.hpp>
#include "src/h/controlHUD.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle life | FrancisStudios");
    sf::Clock clock;

    sf::Font defaultFont;
    if (!defaultFont.loadFromFile("./dist/typeface.ttf"))
    {
        // TODO: font not found or failed to load
    }

    sf::Text ctrlHUD(ControlHUD::init(defaultFont));

    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        float dtAsSeconds = deltaTime.asSeconds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // TODO: <draw method will live here>
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            shape.move(100.0f * dtAsSeconds, 0.0f);
        }
        // TODO: </draw>

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(ctrlHUD);
        window.display();
    }

    return 0;
}