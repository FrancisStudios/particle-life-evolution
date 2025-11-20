/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/simulation.h"

Simulation &Simulation::getInstance()
{
    static Simulation instance;
    return instance;
}

/**
 * Adds an entity into Entity entities[] and returns
 * the index of the added entity for later selection
 */
int Simulation::addEntity(Entity entity)
{
    Simulation::entities[addedEntites] = entity;
    Simulation::addedEntites++;
    return Simulation::addedEntites - 1;
}