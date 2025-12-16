/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include <SFML/Graphics.hpp>
#include "src/h/controlHUD.h"
#include "src/h/fontloader.h"
#include "src/h/util.h"
#include "src/h/debugHUD.h"
#include "src/h/logger.h"
#include "src/h/json.h"
#include "src/h/simulationConfig.h"
#include "src/h/simulation.h"
#include "src/h/force.h"
#include "src/h/renderer.h"
#include "src/h/toggles.h"

#ifdef _WIN32
#define SIM_CONFIG "../../sim.config.json" // TODO: in prod it should be ./sim...
#elif __linux__
#define SIM_CONFIG "sim.config.json"
#endif

int main()
{
    /**
     * Setup process - general variables and class initializations
     * ======== This is where all the control flow starts ========
     */
    JSONOps::loadSimulatorConfig(SIM_CONFIG);

    SimConfig &simulationConfig = SimConfig::getInstance();
    Simulation &simulation = Simulation::getInstance();

    sf::RenderWindow window(
        sf::VideoMode(simulationConfig.getSimulationSize().width,
                      simulationConfig.getSimulationSize().height),
        Util::WINDOW_TITLE());

    sf::Clock clock;
    Logger &log = Logger::getInstance();
    sf::Font defaultFont = FontLoader::loadDefault();
    sf::Text controlHUD = ControlHUD::init(defaultFont);
    sf::Text debugHUD = DebugHUD::init(defaultFont);

    bool debugMode = false;
    bool debugButtonEnabled = true;

    bool isSimulationStarted = false;
    bool isSimStartedBtnEnabled = true;

    float debugButtonEnableTimer = 0.0f;
    float simStartedBtnEnableTimer = 0.0f;

    log.turnOnLogger();

    /**
     * ================= [Statical Processes] =================
     * Like preprocessing data or setting up pre-simulation vars.
     */
    Generator::assembleEntitiesForRender();

    /**
     * ================= [Game Loop Process] =================
     * Simulation frame processing is down below - EZ as that.
     */
    while (window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        float dtAsSeconds = deltaTime.asSeconds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            window.close();

        Toggles::detectIfSimulationIsStarted(
            isSimStartedBtnEnabled,
            isSimulationStarted,
            simStartedBtnEnableTimer,
            dtAsSeconds);

        Toggles::detectIfDebugMenuIsActivated(
            debugButtonEnabled,
            debugMode,
            debugButtonEnableTimer,
            dtAsSeconds);

        window.clear(sf::Color::Black);

        if (debugMode)
            window.draw(debugHUD);

        Renderer::renderEntities(window, dtAsSeconds, isSimulationStarted);

        window.draw(controlHUD);
        window.display();
    }

    return 0;
}