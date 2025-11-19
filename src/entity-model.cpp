/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/entity-model.h"

#define COLOR_RED "red"
#define COLOR_BLUE "blue"
#define COLOR_GREEN "green"
#define COLOR_YELLOW "yellow"

Entity::Entity(string name, string color, float speed, Coord2D position)
{
    Entity::name = name;
    Entity::color = Entity::findColorByName(color.c_str());
    Entity::speed = speed;
    Entity::position = position;
}

void Entity::buildEntity()
{
    Entity::cell.setFillColor(Entity::color);
}

sf::Color Entity::findColorByName(const char *name)
{
    if (strcmp(name, COLOR_RED) == 0)
    {
        return sf::Color::Red;
    }
    else if (strcmp(name, COLOR_GREEN) == 0)
    {
        return sf::Color::Green;
    }
    else if (strcmp(name, COLOR_BLUE) == 0)
    {
        return sf::Color::Blue;
    }
    else if (strcmp(name, COLOR_YELLOW) == 0)
    {
        return sf::Color::Yellow;
    }
    else
    {
        return sf::Color::White;
    }
    // TODO: get rid of this Yandere simulator-esque quality code
    // TODO: as soon as version 1.0.0 rolls out (maybe in the first)
    // TODO: patches or smth. Temporary solution, calm down U"w"U
}