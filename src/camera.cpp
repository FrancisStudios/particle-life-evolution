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
}

void Camera::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y -= cameraSpeed * deltaTime;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        position.y += cameraSpeed * deltaTime;
    }
}