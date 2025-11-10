/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include <SFML/Graphics.hpp>
#include "src/h/controlHUD.h"
#include "src/h/fontloader.h"
#include "src/h/util.h"
#include "src/h/debugHUD.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), Util::WINDOW_TITLE());

    sf::Clock clock;
    sf::Font defaultFont = FontLoader::loadDefault();
    sf::Text controlHUD = ControlHUD::init(defaultFont);
    sf::Text debugHUD = DebugHUD::init(defaultFont);

    bool debugMode = false;

    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(395.0f, 295.0f);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            shape.move(100.0f * dtAsSeconds, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            shape.move(-100.0f * dtAsSeconds, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            shape.move(0.0f, -100.0f * dtAsSeconds);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            shape.move(0.0f, 100.0f * dtAsSeconds);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
            debugMode = !debugMode;

        window.clear(sf::Color::Black);

        if (debugMode)
            window.draw(debugHUD);

        window.draw(shape);
        window.draw(controlHUD);
        window.display();
    }

    return 0;
}