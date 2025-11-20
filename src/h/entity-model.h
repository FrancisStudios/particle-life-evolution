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

using namespace std;

class Entity
{
private:
    sf::CircleShape cell;

    string name;
    sf::Color color;
    float speed;
    Coord2D position;
    Coord2D direction;

    void buildEntity();

public:
    Entity();
    Entity(string name, string color, float speed, Coord2D position);

    static sf::Color findColorByName(const char *name);
};
#endif