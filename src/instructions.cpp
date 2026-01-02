/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#include "./h/instructions.h"

namespace InstructionsWindow
{
    void open(sf::RenderWindow &window, sf::Font &typeface)
    {
        /* Dialog window elements */
        sf::RectangleShape dialogWindow;

        dialogWindow.setPosition({IW_MARGIN, IW_MARGIN});
        dialogWindow.setSize(
            {(float)(window.getSize().x - IW_MARGIN * 2),
             (float)(window.getSize().y - IW_MARGIN * 2)});

        dialogWindow.setFillColor(sf::Color(0x00, 0x3a, 0x6b, 0xef));

        /* Dialog window title and subtext */
        sf::Text dialogTitle;
        setDefaultTextProperties(
            dialogTitle,
            "Particle Life Simulator Instructions",
            typeface,
            30);

        dialogTitle.setPosition({(float)dialogWindow.getSize().x / 2 - 180,
                                 50.0f});

        window.draw(dialogWindow);
        window.draw(dialogTitle);
    }

    void setDefaultTextProperties(sf::Text &textHandler, std::string textContent, sf::Font &typeface, int textSize)
    {
        textHandler.setCharacterSize(textSize);
        textHandler.setFont(typeface);
        textHandler.setString(textContent);
    }
}