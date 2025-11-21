/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/simulationConfig.h"

SimConfig &SimConfig::getInstance()
{
    static SimConfig instance;
    return instance;
}

void SimConfig::setParticleSize(float pSize)
{
    SimConfig::particleSize = pSize;
}

float SimConfig::getParticleSize()
{
    return SimConfig::particleSize;
}

void SimConfig::setSeed(std::string seed)
{
    SimConfig::seed = seed;
}

std::string SimConfig::getSeed()
{
    return SimConfig::seed;
}

void SimConfig::setEntityCount(int n)
{
    SimConfig::entityCount = (int)n;
}

int SimConfig::getEntityCount()
{
    return SimConfig::entityCount;
}

void SimConfig::setSpeciesCount(int n)
{
    SimConfig::speciesCount = n;
}

int SimConfig::getSpeciesCount()
{
    return SimConfig::speciesCount;
}

void SimConfig::setSimulationSize(SimulationSize2D &_simulationSize)
{
    SimConfig::simulationSize = _simulationSize;
}

SimulationSize2D &SimConfig::getSimulationSize()
{
    return SimConfig::simulationSize;
}