/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef SIM_CONF_H
#define SIM_CONF_H
#pragma once

#include <string>
#include "util.h"

class SimConfig
{
private:
    SimConfig() {}
    ~SimConfig() {}
    SimConfig(const SimConfig &) = delete;
    SimConfig &operator=(const SimConfig &) = delete;

    SimulationSize2D simulationSize;
    float particleSize;
    std::string seed;
    int entityCount;
    int speciesCount;

public:
    ForceVector entityForces[12]; // TODO: make it dynamic
    static SimConfig &getInstance();
    void setParticleSize(float particleSize);
    float getParticleSize();
    void setSeed(std::string seed);
    std::string getSeed();
    void setEntityCount(int count);
    int getEntityCount();
    void setSpeciesCount(int count);
    int getSpeciesCount();
    void setSimulationSize(SimulationSize2D &simulationSize);
    SimulationSize2D &getSimulationSize();
    int getForceVectorCount();
};

#endif