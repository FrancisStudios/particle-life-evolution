/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef GENERATOR_H
#define GENERATOR_H
#pragma once

#include "./simulationConfig.h"
#include "./simulation.h"
#include <nlohmann/json.hpp>

namespace Generator
{
    void createEntities(const nlohmann::json_abi_v3_12_0::json &data);
}

#endif