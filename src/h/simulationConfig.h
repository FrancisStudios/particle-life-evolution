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

class SimConfig
{
private:
    SimConfig() {}
    ~SimConfig() {}
    SimConfig(const SimConfig &) = delete;
    SimConfig &operator=(const SimConfig &) = delete;

    float particleSize;

public:
    static SimConfig &getInstance();
    void setParticleSize(float particleSize);
    float getParticleSize();
};

#endif