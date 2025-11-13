/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */
#ifndef LOGGER_H
#define LOGGER_H
#pragma once

#include <stdio.h>
#include <string>
#include "./util.h"

class Logger
{
private:
    Logger() {}
    ~Logger() {}
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    bool isLoggerOn;

public:
    static Logger &getInstance();
    void turnOnLogger();
    void turnOffLogger();
    void toggleLogger();
    void print(const char buffer[], int logLevel);
};

#endif