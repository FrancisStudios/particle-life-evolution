/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef RENDERER_H
#define RENDERER_H

#include "util.h"
#include <SFML/Graphics.hpp>
#include "simulationConfig.h"
#include "simulation.h"
#include "force.h"

#pragma once

namespace Renderer
{
    void renderEntities(sf::RenderWindow &window, float deltaTimeS, bool isSimulationStarted);
    bool loopingThroughEachEntity(int entityIndex, int entityCount);
    bool loopingThroughOtherEntitiesForRelations(int observedEntityIndex, int otherEntityIndex, int entityCount);
    bool isInDetectionRange(Coord2D &thisEntitysPosition, Coord2D &otherEntitysPosition, float thisEntitysDetectionRadius);
}

#endif