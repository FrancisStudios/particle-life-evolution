/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/debugHUD.h"

namespace DebugHUD
{
    sf::Text init(const sf::Font &typeFace, float x, float y, int fontsize)
    {

        sf::Text HUD;
        std::ostringstream HUDTemplate;
        HUDTemplate << "DEBUG COMES HERE";

        HUD.setString(HUDTemplate.str());
        HUD.setCharacterSize(fontsize);
        HUD.setPosition(x, y);
        HUD.setFont(typeFace);

        return HUD;
    }
}