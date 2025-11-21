/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef ENTITY_MODEL_H
#define ENTITY_MODEL_H
#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include "./util.h"

#define COLOR_RED "red"
#define COLOR_BLUE "blue"
#define COLOR_GREEN "green"
#define COLOR_YELLOW "yellow"
#define BLANK_ENTITY_NAME "_blank"
#define DEFAULT_COLOR "_blank_color"
#define DEFAULT_SPEED 0.0f
#define DEFAULT_VECTOR2DF {0.0f, 0.0f}

using namespace std;

namespace Entity
{
    sf::Color findColorByName(const char *name);

    struct Cell
    {
        // TODO: sf::CircleShape shape; some impementation
        string name;
        sf::Color color;
        float speed;
        Coord2D position;
        Coord2D direction;

        Cell(string _name, sf::Color _color, float _speed, Coord2D _position, Coord2D _direction)
        {
            name = _name;
            color = _color;
            speed = _speed;
            position = _position;
            direction = _direction;
        }

        Cell()
        {
            name = BLANK_ENTITY_NAME;
            color = findColorByName(DEFAULT_COLOR);
            speed = DEFAULT_SPEED;
            position = DEFAULT_VECTOR2DF;
            direction = DEFAULT_VECTOR2DF;
        }
    };
}

#endif