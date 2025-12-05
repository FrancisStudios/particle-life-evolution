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

#ifdef _WIN32
#define SIM_CONFIG "../../sim.config.json" // TODO: in prod it should be ./sim...
#elif __linux__
#define SIM_CONFIG "sim.config.json"
#endif

#define BUTTON_TIMER_LIMIT 0.5f

void detectIfDebugMenuIsActivated(
    bool &debugButtonEnabled,
    bool &debugMode,
    float &debugButtonEnableTimer,
    float dtAsSeconds)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && debugButtonEnabled)
    {
        debugMode = !debugMode;
        debugButtonEnabled = false;
    }

    if (!debugButtonEnabled)
    {
        debugButtonEnableTimer += dtAsSeconds;
        if (debugButtonEnableTimer > BUTTON_TIMER_LIMIT)
        {
            debugButtonEnableTimer = 0.0f;
            debugButtonEnabled = true;
        }
    }
}

void assembleEntitiesFromData(SimConfig &simulationConfig, Simulation &simulation)
{
    for (int i = 0; i < simulationConfig.getEntityCount(); i++)
    {
        Coord2D randomPosition = Util::generateRandomCoordinate(
            simulationConfig.getParticleSize(),
            simulationConfig.getSimulationSize().width,
            simulationConfig.getSimulationSize().height);

        simulation.getEntity(i).shape.setRadius(simulationConfig.getParticleSize());
        simulation.getEntity(i).shape.setFillColor(simulation.getEntity(i).color);
        simulation.getEntity(i).shape.setPosition({randomPosition.x, randomPosition.y});
    }
}

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
    assembleEntitiesFromData(simulationConfig, simulation);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            shape.move(100.0f * dtAsSeconds, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            shape.move(-100.0f * dtAsSeconds, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            shape.move(0.0f, -100.0f * dtAsSeconds);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            shape.move(0.0f, 100.0f * dtAsSeconds);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            window.close();

        detectIfDebugMenuIsActivated(
            debugButtonEnabled,
            debugMode,
            debugButtonEnableTimer,
            dtAsSeconds);

        window.clear(sf::Color::Black);

        if (debugMode)
            window.draw(debugHUD);

        /* Entity Renderer Is Here */
        for (int i = 0; i < simulationConfig.getEntityCount(); i++)
        {
            sf::Vector2f entityVectors[100 - 1]; // TODO: dynamic sizes in the future
            sf::Vector2f originVector;
            int savedOtherEntity = 0;
            int reducedOtherEntity = 0;

            Coord2D _dFrom = {simulation.getEntity(i).shape.getPosition().x,
                              simulation.getEntity(i).shape.getPosition().y};

            for (int otherEntityIndex = 0; otherEntityIndex < simulationConfig.getEntityCount(); otherEntityIndex++)
            {
                int thisEntityIndex = i;
                if (otherEntityIndex != thisEntityIndex)
                {

                    Coord2D _dTo = {simulation.getEntity(otherEntityIndex).shape.getPosition().x,
                                    simulation.getEntity(otherEntityIndex).shape.getPosition().y};

                    sf::Vector2f otherEntityPos;
                    otherEntityPos.x = _dTo.x;
                    otherEntityPos.y = _dTo.y;

                    float forceToOtherEntity = 1.0f; // TODO: get from sim

                    float distance = Force::getDistance(_dFrom, _dTo);

                    if (distance <= simulation.getEntity(thisEntityIndex).detection_radius)
                    {
                        entityVectors[savedOtherEntity] = Force::createVector(otherEntityPos, forceToOtherEntity);
                        savedOtherEntity++;
                    }
                }
            }

            // Reduce entity vectors array.prototype.reduce() XD Javascript brain Francis
            while (savedOtherEntity != reducedOtherEntity)
            {
                printf("Entityvectors x: %f, y: %f \n", entityVectors[reducedOtherEntity].x,  entityVectors[reducedOtherEntity].y);
                reducedOtherEntity++;
            }

            printf("reduced\n");

            window.draw(simulation.getEntity(i).shape);
        }

        window.draw(shape);
        window.draw(controlHUD);
        window.display();
    }

    return 0;
}