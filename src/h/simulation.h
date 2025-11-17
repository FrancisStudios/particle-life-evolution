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

class Simulation
{
private:
    Simulation() {};
    ~Simulation() {};
    Simulation(const Simulation &) = delete;
    Simulation &operator=(const Simulation &) = delete;

public:
    static Simulation &getInstance();
};

#endif