/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef TOGGLES_H
#define TOGGLES_H

#define BUTTON_TIMER_LIMIT 0.5f

#include <SFML/Graphics.hpp>

#pragma once

namespace Toggles
{
    void detectIfDebugMenuIsActivated(bool &debugButtonEnabled, bool &debugMode, float &debugButtonEnableTimer, float deltaTimeS);
}

#endif