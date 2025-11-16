/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/entity-model.h"

Entity::Entity(string name, string color, float speed, Coord2D position)
{
    Entity::name = name;
    Entity::speed = speed;
    Entity::position = position;
}