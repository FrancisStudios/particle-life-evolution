/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/entity-model.h"

namespace Entity
{
    sf::Color findColorByName(const char *name)
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
}
