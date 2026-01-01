/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#include "./h/background.h"

namespace Background
{
    void draw(sf::RenderWindow &window)
    {
        const int width = window.getSize().x;
        const int height = window.getSize().y;
       // const sf::Color defaultColor = sf::Color(0x2c, 0x45, 0x6b, 0xa0);
        const sf::Color defaultColor = sf::Color(0x3c, 0x64, 0x9f, 0xa0);

        const sf::Color clearColor(0x00, 0x1a, 0x33);
        window.clear(clearColor);

        for (int row = 1; row < width; row += ROW_GAP)
        {
            for (int column = 0; column < height; column += COLUMN_GAP)
            {
                sf::RectangleShape horizontal;
                sf::RectangleShape vertical;

                horizontal.setSize({CROSS_SIZE, 1});
                horizontal.setPosition({(float)row, (float)column});
                horizontal.setOutlineThickness(LINE_THICKNESS);
                horizontal.setFillColor(defaultColor);
                horizontal.setOutlineColor(defaultColor);

                vertical = horizontal;

                vertical.setPosition({(float)row + (CROSS_SIZE / 2),
                                      (float)column - (CROSS_SIZE / 2)});

                vertical.rotate(90.0f);

                window.draw(horizontal);
                window.draw(vertical);
            }
        }
    }
}