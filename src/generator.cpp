/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/generator.h"

namespace Generator
{
    void createEntities(const nlohmann::json_abi_v3_12_0::json &data)
    {
        SimConfig &simulationConfig = SimConfig::getInstance();

        int _speciesCount = simulationConfig.getSpeciesCount();
        int speciesCountEquilibrian = 0;
        int speciesTypeSelector = 0;

        while (speciesCountEquilibrian < _speciesCount)
        {
            if (speciesTypeSelector == _speciesCount)
                speciesTypeSelector = 0;

            // TODO: generation comes here -> should populate simulation class with <Entity>

            speciesTypeSelector++;
            speciesCountEquilibrian++;
        }
    }
}