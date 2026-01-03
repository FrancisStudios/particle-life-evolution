/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/controlHUD.h"

#define DIVIDER " | "
#define EXIT "[E]xit"
#define START "[S]tart"
#define STOP "[S]top"
#define INSTRUCTIONS "[I]nstructions"
#define IW_CLOSE "[I] Close Panel"
#define DEBUG "[F3] Debug"

namespace ControlHUD
{
    sf::Text init(const sf::Font &typeFace, float x, float y, int fontsize)
    {
        sf::Text HUD;
        std::ostringstream HUDOptions;

        HUDOptions << EXIT
                   << DIVIDER
                   << START
                   << DIVIDER
                   << INSTRUCTIONS
                   << DIVIDER
                   << DEBUG;

        HUD.setString(HUDOptions.str());
        HUD.setCharacterSize(fontsize);
        HUD.setPosition(x, y);
        HUD.setFont(typeFace);

        return HUD;
    }

    std::string update(bool isSimStarted, bool isInstructionsOpen)
    {
        std::ostringstream HUDOptions;
        std::string START_OR_STOP = !isSimStarted ? START : STOP;
        std::string INSTRUCTIONS_OR_CLOSE = isInstructionsOpen ? IW_CLOSE : INSTRUCTIONS;

        HUDOptions << EXIT
                   << DIVIDER
                   << START_OR_STOP
                   << DIVIDER
                   << INSTRUCTIONS_OR_CLOSE
                   << DIVIDER
                   << DEBUG;

        return HUDOptions.str();
    }

    void drawCreditMark(const sf::Font &typeface, sf::RenderWindow &window)
    {
        sf::Text creditMark;
        sf::Vector2u screenSize = window.getSize();

        creditMark.setString(REPOSITORY);
        creditMark.setCharacterSize(15);
        creditMark.setPosition(screenSize.x - 330, screenSize.y - 30);
        creditMark.setFont(typeface);

        window.draw(creditMark);
    }
}