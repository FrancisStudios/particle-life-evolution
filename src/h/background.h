/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once

#include <SFML/Graphics.hpp>

#define ROW_GAP 50
#define COLUMN_GAP 50
#define CROSS_SIZE 6
#define LINE_THICKNESS 0.2f

namespace Background
{
    void draw(sf::RenderWindow &window);
}

#endif