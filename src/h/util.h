/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef UTIL_H
#define UTIL_H
#pragma once

#include <string>
#include <sstream>
#include <random>
#include <chrono>

#define APP_NAME "Particle Life"
#define APP_VERSION "v0.4.8"
#define AUTHOR "by FrancisStudios"
#define SPACING " "
#define DIVIDER " | "
#define MARGIN 10
#define REPOSITORY "github.com/francisstudios/particle-life-evolution"

#ifdef _WIN32
#define OS "for Windows"
#elif __linux__
#define OS "for Linux"
#endif

struct Coord2D
{
    float x;
    float y;
};

namespace Util
{
    std::string WINDOW_TITLE();

    template <typename C>
    inline int strcpy_s(C *d, unsigned long dmax, const C *s);

    double frandom(double min, double max);

    Coord2D generateRandomCoordinate(float particleSize, int window_x, int window_y);
};

struct SimulationSize2D
{
    int width;
    int height;
};

struct ForceVector
{
    std::string from;
    std::string to;
    float force;
};
#endif