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
    void renderEntities()
    {
        int entitySelectionIndex = 0;
        while (loopingThroughEachEntity(entitySelectionIndex))
        {
            Coord2D thisEntitysPosition = {10.0f, 10.0f};
            entitySelectionIndex++;
        }
    }

    bool loopingThroughEachEntity(int entitySelectionIndex)
    {
        // TODO:  for (int i = 0; i < simulationConfig.getEntityCount(); i++)
        // TODO:  would be rewritten here in a boolean logic to keep the while
        // TODO:  loop running while entites are looping
        return false;
    }
}