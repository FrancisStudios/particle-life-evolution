/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */
#ifndef SIMULATION_H
#define SIMULATION_H
#pragma once

#include "./entity-model.h"

class Simulation
{
private:
    Simulation() {};
    ~Simulation() {};
    Simulation(const Simulation &) = delete;
    Simulation &operator=(const Simulation &) = delete;

    Entity::Cell *entities;
    int addedEntites = 0;

public:
    static Simulation &getInstance();
    int addEntity(Entity::Cell &e);
    const Entity::Cell &getEntity(int index) const;
    Entity::Cell &getEntity(int _index);
    void setEntityCount(int entityCount) { this->entities = new Entity::Cell[entityCount]; };
};

#endif