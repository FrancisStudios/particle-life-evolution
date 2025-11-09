/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/controlHUD.h"

namespace ControlHUD
{
    sf::Text init(const sf::Font &typeFace, float x, float y, int fontsize)
    {
        sf::Text HUD;

        HUD.setString("[S]tart");
        HUD.setCharacterSize(fontsize);
        HUD.setPosition(x, y);
        HUD.setFont(typeFace);
        HUD.setFillColor(sf::Color::White);

        return HUD;
    }
}