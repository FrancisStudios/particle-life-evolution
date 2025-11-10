
/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef DEBUG_HUD_H
#define DEBUG_HUD_H
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

namespace DebugHUD
{
    sf::Text init(const sf::Font &typeFace, float x = 5.0f, float y = 100.0f, int fontsize = 24);
}

#endif
