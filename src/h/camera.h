/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#ifndef CAMERA_H
#define CAMERA_H
#pragma once

#include <SFML/Graphics.hpp>
#include "./util.h"
#include "./simulation.h"
#include "./simulationConfig.h"

class Camera
{
private:
    Camera() {};
    ~Camera() {};
    Camera(const Camera &) = delete;
    Camera &operator=(const Camera &) = delete;
    Coord2D position;
    Coord2D absolutePosition = {0.0f, 0.0f};
    float zoom = 1.0;
    float cameraSpeed = 200.0f;
    float zoomSpeed = 10.0f;
    void updateEntitesWithCameraPosition();
    void updateEntitesWithCameraZoom();

public:
    static Camera &getInstance();
    void init();
    Coord2D *getCameraPosition() { return &this->position; };
    void setNewCameraPosition(Coord2D newPos) { this->position = newPos; };
    void update(float deltaTime);
    Coord2D &getAbsolutePosition() { return this->absolutePosition; };
};

#endif