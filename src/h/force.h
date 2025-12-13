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
    float getDistance(const Coord2D &from, const Coord2D &to);
    sf::Vector2f sumVectors(sf::Vector2f vA, sf::Vector2f vB);
    sf::Vector2f createVector(Coord2D &from, Coord2D &to, float force, float particleSize);
    sf::Vector2f keepItInBounds(sf::Vector2f target, int xBound, int yBound);
    void brownMovementsActivator(sf::Vector2f &originVector);
}

#endif