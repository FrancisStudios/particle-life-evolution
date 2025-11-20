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
        Simulation &simulation = Simulation::getInstance();

        int _speciesCount = simulationConfig.getSpeciesCount();
        int _entityCount = simulationConfig.getEntityCount();
        int counter = 0;
        int speciesTypeSelector = 0;

        while (counter < _entityCount)
        {
            if (speciesTypeSelector == _speciesCount)
                speciesTypeSelector = 0;

            // TODO: generation comes here -> should populate simulation class with <Entity>
            // Entity Factory
            Entity product = Entity(
                (std::string)data["species"][speciesTypeSelector]["name"],
                (std::string)data["species"][speciesTypeSelector]["color"],
                (float)data["species"][speciesTypeSelector]["speed"],
                {10.0f, 10.0f});

            //simulation.addEntity(product);

            speciesTypeSelector++;
            counter++;
        }
    }
}