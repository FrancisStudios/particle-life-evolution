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
    float debugButtonEnableTimer = 0.0f;

    log.turnOnLogger();

    sf::CircleShape shape(simulationConfig.getParticleSize());

    shape.setFillColor(sf::Color::Green);
    shape.setPosition(395.0f, 295.0f);

    /* Statical Processes Should Come Here - maybe reorg later */
    Generator::assembleEntitiesForRender();

    /* Dynamical Processes Should Come Here - maybe reorg later */
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

        Toggles::detectIfDebugMenuIsActivated(
            debugButtonEnabled,
            debugMode,
            debugButtonEnableTimer,
            dtAsSeconds);

        window.clear(sf::Color::Black);

        if (debugMode)
            window.draw(debugHUD);

        Renderer::renderEntities(window, dtAsSeconds, true);

        window.draw(controlHUD);
        window.display();
    }

    return 0;
}