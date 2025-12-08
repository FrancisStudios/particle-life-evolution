/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/renderer.h"
const bool isSimulationStarted = false;

namespace Renderer
{
    // TODO: get window reference from main
    void renderEntities()
    {
        SimConfig &simulationConfig = SimConfig::getInstance();
        Simulation &simulation = Simulation::getInstance();

        const int entityCount = simulationConfig.getEntityCount();

        /* 1) Looping through each entity to map out their relations */
        int thisEntityIndex = 0;
        while (loopingThroughEachEntity(thisEntityIndex, entityCount))
        {
            Coord2D thisEntitysPosition = {
                simulation.getEntity(thisEntityIndex).shape.getPosition().x,
                simulation.getEntity(thisEntityIndex).shape.getPosition().y};

            sf::Vector2f thisEntitysVectors[100-1]; //TODO: dynamics sizing in a future ver;

            float thisEntitysDetectionRadius = simulation.getEntity(thisEntityIndex).detection_radius;
            int nextThisEntitysVectorIndex = 0;

            /* 2) Comparing with every other entity who is in range */
            int comparedEntityIndex = 0;
            while (loopingThroughOtherEntitiesForRelations(
                thisEntityIndex,
                comparedEntityIndex,
                entityCount))
            {
                Coord2D otherEntitysPosition = {
                    simulation.getEntity(comparedEntityIndex).shape.getPosition().x,
                    simulation.getEntity(comparedEntityIndex).shape.getPosition().y};

                if (isInDetectionRange(thisEntitysPosition, otherEntitysPosition, thisEntitysDetectionRadius) && isSimulationStarted)
                {
                    float forceToOtherEntity = 1.0f; 
                    //thisEntitysVectors[nextThisEntitysVectorIndex] = Force::createVector(otherEntitysPosition, forceToOtherEntity); 
                    //TODO: rethink create vector function in force so it's more native to SFML renderer or rather sf::Shape.move() method
                }

                comparedEntityIndex++;
            }

            // window.draw(simulation.getEntity(thisEntitysIndex).shape)
            thisEntityIndex++;
        }
    }

    bool loopingThroughEachEntity(int entityIndex, int entityCount)
    {
        return (entityIndex < entityCount);
    }

    bool loopingThroughOtherEntitiesForRelations(int observedEntityIndex, int otherEntityIndex, int entityCount)
    {
        return ((observedEntityIndex != otherEntityIndex) && (otherEntityIndex < entityCount));
    }

    bool isInDetectionRange(Coord2D &thisEntitysPosition, Coord2D &otherEntitysPosition, float thisEntitysDetectionRadius)
    {
        float distance = Force::getDistance(thisEntitysPosition, otherEntitysPosition);
        return (distance <= thisEntitysDetectionRadius);
    }
}