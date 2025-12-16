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
                   << DEBUG;

        HUD.setString(HUDOptions.str());
        HUD.setCharacterSize(fontsize);
        HUD.setPosition(x, y);
        HUD.setFont(typeFace);

        return HUD;
    }

    std::string update(bool isSimStarted)
    {
        std::ostringstream HUDOptions;
        std::string START_OR_STOP = isSimStarted ? START : STOP;

        HUDOptions << EXIT
                   << DIVIDER
                   << START_OR_STOP
                   << DIVIDER
                   << DEBUG;

        return HUDOptions.str();
    }
}