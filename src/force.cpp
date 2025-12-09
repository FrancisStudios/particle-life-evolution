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

    sf::Vector2f createVector(sf::Vector2f target, float force)
    {
        sf::Vector2f vector;
        vector.x = target.x * force;
        vector.y = target.y * force;
        return vector;
    }

    sf::Vector2f createVectorNew(Coord2D from, Coord2D to, float force)
    {
        sf::Vector2f output;

        // 1) Determine how many steps do we have to take to reach the spot
        //  from "from" to get to "to" so we can use the sf::Shape.move()
        float xDifference = from.x - to.x;
        float yDifference = from.y - to.y;

        // 2) We have to invert signs to have the correct direction for the
        // two cases
        xDifference = xDifference * -1;
        yDifference = yDifference * -1;

        // 3) Use the force, anakin use the force :D :D :D :D - I'm so funny
        output.x = xDifference * force;
        output.y = yDifference * force;

        return output;
    }

    sf::Vector2f keepItInBounds(sf::Vector2f target, int xBound, int yBound)
    {
        // TODO: make a better algorythm later
        sf::Vector2f vector;

        target.x > xBound
            ? vector.x = target.x - (float)xBound
            : vector.x = target.x;

        target.y > yBound
            ? vector.y = target.y - (float)yBound
            : vector.y = target.y;

        return vector;
    }
}