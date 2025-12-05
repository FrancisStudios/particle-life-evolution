/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/force.h"

namespace Force
{
    float getDistance(Coord2D from, Coord2D to)
    {
        float dx = to.x - from.x;
        float dy = to.y - from.y;

        float pythagorasBlin = (dx * dx) + (dy * dy);

        return std::sqrt(pythagorasBlin);
    }

    sf::Vector2f sumVectors(sf::Vector2f vA, sf::Vector2f vB)
    {
        sf::Vector2f vector;
        vector.x = vA.x + vB.x;
        vector.y = vA.y + vB.y;
        return vector;
    }

    sf::Vector2f createVector()
    {
        sf::Vector2f vector;
        return vector;
    }

}