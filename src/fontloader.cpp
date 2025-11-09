/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/fontloader.h"

#ifdef _WIN32
#define TYPEFACE_LOCATION "typeface.ttf"
#elif __linux__
#define TYPEFACE_LOCATION "./dist/linux/typeface.ttf"
#endif

namespace FontLoader
{
    sf::Font loadDefault()
    {
        sf::Font defaultFont;
        if (!defaultFont.loadFromFile(TYPEFACE_LOCATION))
        {
            // TODO: font not found or failed to load
        }

        return defaultFont;
    }
}
