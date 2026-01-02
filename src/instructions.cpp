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

        /* Instructions description and such*/
        std::ostringstream instructionsDescriptionTemplate;
        sf::Text instructionsDescription;
        instructionsDescriptionTemplate << "Welcome to my Particle life simulator! I hope you will enjoy exploring and experimenting with this tool. \n"
                                        << "This application was made by L. (Francis) as a recreational programming project and an experimentation \n"
                                        << "with particle simulations - and in later versions maybe machine learning and evolutionary programming. \n"
                                        << "\n"
                                        << "------------------------ [Instructions] ------------------------\n"
                                        << "[Arrows]    Move the camera (observer) in different directions \n"
                                        << "[E]         Exit the application \n"
                                        << "[F3]        Show debug information \n"
                                        << "[I]         Show and hide instructions panel\n"
                                        << "------------------------------------------------------------------\n"
                                        << "\n"
                                        << "Project started on 2025 november 6 | C++ | SFML 2.6 | GCC 15.2.0 \n"
                                        << "built for Linux and Windows operating systems\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "\n"
                                        << "                                                      | PRESS [I] TO CLOSE THIS DIALOG |";
        setDefaultTextProperties(
            instructionsDescription,
            instructionsDescriptionTemplate.str(),
            typeface);
        instructionsDescription.setPosition(
            (float)((IW_MARGIN * 2) - DEFAULT_IW_TEXT_SIZE),
            (float)(IW_MARGIN * 2));

        window.draw(dialogWindow);
        window.draw(dialogTitle);
        window.draw(instructionsDescription);
    }

    void setDefaultTextProperties(sf::Text &textHandler, std::string textContent, sf::Font &typeface, int textSize)
    {
        textHandler.setCharacterSize(textSize);
        textHandler.setFont(typeface);
        textHandler.setString(textContent);
    }
}