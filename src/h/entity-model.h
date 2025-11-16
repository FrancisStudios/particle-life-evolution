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
#include "./util.h"

using namespace std;

class Entity
{
private:
    string name;
    sf::Color color;
    float speed;
    Coord2D position;
    Coord2D direction;

public:
    Entity();
    Entity(string name, string color, float speed, Coord2D position);
};

#endif