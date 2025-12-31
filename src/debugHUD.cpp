/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/debugHUD.h"

namespace DebugHUD
{
    sf::Text init(const sf::Font &typeFace, float x, float y, int fontsize)
    {

        sf::Text HUD;
        std::ostringstream HUDTemplate;
        HUDTemplate << "=== [Debug Menu] ===";

        HUD.setString(HUDTemplate.str());
        HUD.setCharacterSize(fontsize);
        HUD.setPosition(x, y);
        HUD.setFont(typeFace);

        return HUD;
    }

    void displayDebugData(const sf::Font &typeFace, sf::RenderWindow &window, float deltaTime)
    {

        std::vector<sf::Text> DebugDataEntries;

        SimConfig &simulationConfig = SimConfig::getInstance();
        Simulation &simulation = Simulation::getInstance();

        std::ostringstream FPSCounterTemplate;
        FPSCounterTemplate << "FRAMERATE: "
                           << (float)(1 / deltaTime);

        std::ostringstream EntityCountDisplay;
        EntityCountDisplay << "SIMULATING "
                           << simulationConfig.getEntityCount()
                           << " ENTITIES";

        std::ostringstream SpeciesCountDisplay;
        SpeciesCountDisplay << "SIMULATING "
                           << simulationConfig.getSpeciesCount()
                           << " SPECIES";

        /* FPS Measurement Unit Display - independent from the counter ln */
        sf::Text FPSMeasurementName;
        setTextAndPosition(FPSMeasurementName, "FPS", {200.0f, 60.0f});
        setDefaultDataDisplayProperties(FPSMeasurementName, typeFace);
        DebugDataEntries.push_back(FPSMeasurementName);

        /* FPS Counter and prefix */
        sf::Text FPSCounter;
        setTextAndPosition(FPSCounter, FPSCounterTemplate.str(), {LEFT_MG, 60.0f});
        setDefaultDataDisplayProperties(FPSCounter, typeFace);
        DebugDataEntries.push_back(FPSCounter);

        /* Entity Count display */
        sf::Text EntityCount;
        setTextAndPosition(EntityCount, EntityCountDisplay.str(), {LEFT_MG, 80.0f});
        setDefaultDataDisplayProperties(EntityCount, typeFace);
        DebugDataEntries.push_back(EntityCount);

        /* Species Count display */
        sf::Text SpeciesCount;
        setTextAndPosition(SpeciesCount, SpeciesCountDisplay.str(), {LEFT_MG, 100.0f});
        setDefaultDataDisplayProperties(SpeciesCount, typeFace);
        DebugDataEntries.push_back(SpeciesCount);

        /* Rendering each text */
        for (int nthDebugDataEntry = 0;
             nthDebugDataEntry < DebugDataEntries.size();
             nthDebugDataEntry++)
            window.draw(DebugDataEntries[nthDebugDataEntry]);
    }

    void setTextAndPosition(sf::Text &textHandler, std::string text, Coord2D position)
    {
        textHandler.setString(text);
        textHandler.setPosition(position.x, position.y);
    }
    void setDefaultDataDisplayProperties(sf::Text &textHandler, const sf::Font &typeface)
    {
        textHandler.setCharacterSize(DATA_CHARSIZE);
        textHandler.setFont(typeface);
    }
}