/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/fontloader.h"

namespace FontLoader
{
    sf::Font loadDefault()
    {
        sf::Font defaultFont;
        if (!defaultFont.loadFromFile("./dist/typeface.ttf"))
        {
            // TODO: font not found or failed to load
        }

        return defaultFont;
    }
}
