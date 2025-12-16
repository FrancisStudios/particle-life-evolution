/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef CONTROL_HUD_H
#define CONTROL_HUD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

namespace ControlHUD
{
    sf::Text init(const sf::Font &typeFace, float x = 5.0f, float y = 1.0f, int fontsize = 24);
    std::string update(bool isSimStarted);
};

#endif