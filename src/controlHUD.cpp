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
    sf::Text init(const sf::Font &typeFace)
    {
        sf::Text HUD;
        
        HUD.setString("[S]tart");
        HUD.setCharacterSize(24);
        HUD.setPosition(100.0f, 100.0f);
        HUD.setFont(typeFace);
        HUD.setFillColor(sf::Color::White);

        return HUD;
    }
}