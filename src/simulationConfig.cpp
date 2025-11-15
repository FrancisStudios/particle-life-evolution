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