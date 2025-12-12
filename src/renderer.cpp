/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/renderer.h"

namespace Renderer
{
    void renderEntities(sf::RenderWindow &window, float deltaTimeS, bool isSimulationStarted)
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

            sf::Vector2f thisEntitysVectors[100 - 1]; // TODO: dynamics sizing in a future ver;
            int savedToThisEntityVectors = 0, processedEntityVectors = 0;
            sf::Vector2f originVector = {0.0f, 0.0f};

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
                    float forceToOtherEntity = 0.0f;

                    for (int forcesParser = 0; forcesParser < simulationConfig.getForceVectorCount(); forcesParser++)
                    {
                        const std::string thisEntitysName = simulation.getEntity(thisEntityIndex).name;
                        const std::string otherEntitysName = simulation.getEntity(comparedEntityIndex).name;
                        const std::string fromName = simulationConfig.entityForces[forcesParser].from;
                        const std::string toName = simulationConfig.entityForces[forcesParser].to;

                        bool thisEntityMatch = (strcmp(thisEntitysName.c_str(), fromName.c_str()) == 0);
                        bool otherEntityMatch = (strcmp(otherEntitysName.c_str(), toName.c_str()) == 0);

                        if (thisEntityMatch && otherEntityMatch)
                            forceToOtherEntity = (float)simulationConfig.entityForces[forcesParser].force;
                    }

                    /* 3) Creating a vector depending on the neighbours and where it should go*/
                    thisEntitysVectors[nextThisEntitysVectorIndex] = Force::createVectorNew(
                        thisEntitysPosition,
                        otherEntitysPosition,
                        forceToOtherEntity);

                    savedToThisEntityVectors++;
                }

                comparedEntityIndex++;
            }

            /* 4) Summarizing all vectors into one origin vector*/
            while (savedToThisEntityVectors != processedEntityVectors)
            {
                originVector = Force::sumVectors(originVector, thisEntitysVectors[0]);
                processedEntityVectors++;
            }

            /* 5) Keep origin vector in screen bounds */
            // TODO: originVector = Force::keepItInBounds();
            // TODO: this is the next step for success

            /* 6) Brown movement for entities with 0 vectors*/

            /* 7) Move and render the entities - finally*/
            simulation.getEntity(thisEntityIndex).shape.move(originVector.x * deltaTimeS, originVector.y * deltaTimeS);
            window.draw(simulation.getEntity(thisEntityIndex).shape);
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