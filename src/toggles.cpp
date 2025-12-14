/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/toggles.h"

namespace Toggles
{
    void detectIfDebugMenuIsActivated(
        bool &debugButtonEnabled,
        bool &debugMode,
        float &debugButtonEnableTimer,
        float deltaTimeS)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && debugButtonEnabled)
        {
            debugMode = !debugMode;
            debugButtonEnabled = false;
        }

        if (!debugButtonEnabled)
        {
            debugButtonEnableTimer += deltaTimeS;
            if (debugButtonEnableTimer > BUTTON_TIMER_LIMIT)
            {
                debugButtonEnableTimer = 0.0f;
                debugButtonEnabled = true;
            }
        }
    }
}