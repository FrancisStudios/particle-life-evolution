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
            return sf::Color(0xe5, 0x4c, 0x38, ALPHA_VALUE);
        }
        else if (strcmp(name, COLOR_GREEN) == 0)
        {
            return sf::Color(0x77, 0xdd, 0x77, ALPHA_VALUE);
        }
        else if (strcmp(name, COLOR_BLUE) == 0)
        {
            return sf::Color(0x12, 0x83, 0x94, ALPHA_VALUE);
        }
        else if (strcmp(name, COLOR_YELLOW) == 0)
        {
            return sf::Color(0xfc, 0xfd, 0x98, ALPHA_VALUE);
        }
        else
        {
            return sf::Color(0xff, 0xff, 0xff, ALPHA_VALUE);
        }
        // TODO: get rid of this Yandere simulator-esque quality code
        // TODO: as soon as version 1.0.0 rolls out (maybe in the first)
        // TODO: patches or smth. Temporary solution, calm down U"w"U
    }
}
