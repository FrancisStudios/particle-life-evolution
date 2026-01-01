/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#include "./h/camera.h"

Camera &Camera::getInstance()
{
    static Camera instance;
    return instance;
}

void Camera::init()
{
    /* Initializing camera position */
    this->position.x = 0;
    this->position.y = 0;

    this->absolutePosition.x = 0;
    this->absolutePosition.y = 0;
}

void Camera::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        position.y += cameraSpeed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        position.y -= cameraSpeed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        position.x += cameraSpeed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        position.x -= cameraSpeed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        zoom -= zoomSpeed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        zoom += zoomSpeed * deltaTime;

    if (position.x != 0.0f || position.y != 0.0f)
        updateEntitesWithCameraPosition();

    // TODO: zoom is not yet ready, needs more than
    // TODO: setting scale size on entities - between
    // TODO: space should grow as well
    // if (zoom != 1.0f)
    //     updateEntitesWithCameraZoom();
}

void Camera::updateEntitesWithCameraPosition()
{
    Simulation &simulation = Simulation::getInstance();
    SimConfig &config = SimConfig::getInstance();

    int i = 0;
    while (i < config.getEntityCount())
    {
        simulation
            .getEntity(i)
            .shape
            .move({Camera::position.x, Camera::position.y});

        i++;
    }

    /* Saving absolute position for later features */
    this->absolutePosition.x += position.x;
    this->absolutePosition.y -= position.y;

    /* Resetting camera positions because everything is done now */
    Camera::position.x = 0.0f;
    Camera::position.y = 0.0f;
}

void Camera::updateEntitesWithCameraZoom()
{
    Simulation &simulation = Simulation::getInstance();
    SimConfig &config = SimConfig::getInstance();

    int i = 0;
    while (i < config.getEntityCount())
    {
        simulation
            .getEntity(i)
            .shape
            .setScale({zoom, zoom});

        i++;
    }
}