/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef FORCE_H
#define FORCE_H

#pragma once

#include "util.h"
#include <SFML/Graphics.hpp>

namespace Force
{
    float getDistance(Coord2D from, Coord2D to);
    sf::Vector2f sumVectors(sf::Vector2f vA, sf::Vector2f vB);
    sf::Vector2f createVector(sf::Vector2f vFrom, sf::Vector2f vTo, float vForce);
}

#endif