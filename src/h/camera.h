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

class Camera
{
private:
    Camera() {};
    ~Camera() {};
    Camera(const Camera &) = delete;
    Camera &operator=(const Camera &) = delete;
    Coord2D position;
    float cameraSpeed = 10.0f;

public:
    static Camera &getInstance();
    void init();
    Coord2D *getCameraPosition() { return &this->position; };
    void setNewCameraPosition(Coord2D newPos) { this->position = newPos; };
    void update(float deltaTime);
};

#endif