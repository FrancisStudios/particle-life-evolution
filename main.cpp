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
#include "src/h/camera.h"
#include "src/h/background.h"
#include "src/h/instructions.h"

#ifdef _WIN32
#define SIM_CONFIG "../../sim.config.json"
#elif __linux__
#define SIM_CONFIG "sim.config.json"
#endif

// #define SIM_CONFIG "./sim.config.json"

int main()
{
    /**
     * ================= [   Setup Process   ] =================
     * Global variables and class instantiations - some singletons
     * are first instantiated in other classes #map for example
     */
    JSONOps::loadSimulatorConfig(SIM_CONFIG);

    SimConfig &simulationConfig = SimConfig::getInstance();
    Simulation &simulation = Simulation::getInstance();
    Logger &log = Logger::getInstance();
    Camera &camera = Camera::getInstance();

    sf::RenderWindow window(
        sf::VideoMode(simulationConfig.getSimulationSize().width,
                      simulationConfig.getSimulationSize().height),
        Util::WINDOW_TITLE());

    sf::Clock clock;

    sf::Font defaultFont = FontLoader::loadDefault();
    sf::Text controlHUD = ControlHUD::init(defaultFont);
    sf::Text debugHUD = DebugHUD::init(defaultFont, 5.0f, 33.0f);
    camera.init();

    bool isDebugMode = false;
    bool debugButtonEnabled = true;
    bool isInstructionsOpen = false;

    bool isSimulationStarted = false;
    bool isSimStartedBtnEnabled = true;
    bool isInstructionsWindowEnabled = true;

    float debugButtonEnableTimer = 0.0f;
    float simStartedBtnEnableTimer = 0.0f;
    float instructionsWindowBtnTimer = 0.0f;

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
            isDebugMode,
            debugButtonEnableTimer,
            dtAsSeconds);

        Toggles::detectIfInstructionsWindowIsOpened(
            isInstructionsWindowEnabled,
            isInstructionsOpen,
            instructionsWindowBtnTimer,
            dtAsSeconds);

        /**
         * ================= [Rendering Processes] =================
         * Renderers and displayers are updated down here ^^ ------>
         */

        camera.update(dtAsSeconds);

        /* Layer 0) Render the background */
        Background::draw(window);

        /* Layer 1) Render the entities and simulation */
        Renderer::renderEntities(
            window,
            dtAsSeconds,
            isSimulationStarted,
            isDebugMode);

        /* Layer 2) Head Up Displays for controls and debug data */
        controlHUD
            .setString(
                ControlHUD::update(isSimulationStarted, isInstructionsOpen));
        window.draw(controlHUD);

        DebugHUD::show(
            isDebugMode,
            debugHUD,
            {window, defaultFont, dtAsSeconds},
            camera.getAbsolutePosition());

        /* Layer 3) Instructions dialog if enabled */
        if (isInstructionsOpen)
            InstructionsWindow::open(window, defaultFont);

        ControlHUD::drawCreditMark(defaultFont, window);

                window.display();
    }

    return 0;
}