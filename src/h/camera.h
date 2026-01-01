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

class Camera
{
private:
    Camera() {};
    ~Camera() {};
    Camera(const Camera &) = delete;
    Camera &operator=(const Camera &) = delete;

public:
    static Camera &getInstance();
};

#endif