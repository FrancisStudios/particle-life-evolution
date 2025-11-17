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

class SimConfig
{
private:
    SimConfig() {}
    ~SimConfig() {}
    SimConfig(const SimConfig &) = delete;
    SimConfig &operator=(const SimConfig &) = delete;

    float particleSize;
    std::string seed;
    int entityCount;
    int speciesCount;

public:
    static SimConfig &getInstance();
    void setParticleSize(float particleSize);
    float getParticleSize();
    void setSeed(std::string seed);
    std::string getSeed();
    void setEntityCount(int count);
    int getEntityCount();
    void setSpeciesCount(int count);
    int getSpeciesCount();
};

#endif