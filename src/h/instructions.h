/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "util.h"

#define IW_MARGIN 50
#define DEFAULT_IW_TEXT_SIZE 15

namespace InstructionsWindow
{
    void open(sf::RenderWindow &window, sf::Font &typeface);
    void setDefaultTextProperties(sf::Text &textHandler, std::string textContent, sf::Font &typeface, int textSize = DEFAULT_IW_TEXT_SIZE);
}

#endif