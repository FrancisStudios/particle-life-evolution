/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle life | FrancisStudios");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // TODO: <draw method will live here>

        float xpos = 0.0f;
        while (xpos < 600.f)
        {
            sf::CircleShape shape(10.f);
            shape.setFillColor(sf::Color(100, 250, 50));
            shape.setPosition({xpos, 10.f});
            window.draw(shape);

            xpos += 0.01f;
        }

        window.display();
    }

    return 0;
}