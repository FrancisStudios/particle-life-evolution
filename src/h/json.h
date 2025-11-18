/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef JSON_H
#define JSON_H
#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include "logger.h"
#include "simulationConfig.h"
#include "generator.h"

namespace JSONOps
{
    void loadSimulatorConfig(const std::string &filepath);
    bool isSpeciesCountValid(int SC);

    template <typename T, typename JSONData>
    T getFromSimConfig(const JSONData &data, const std::string &key);
}
#endif