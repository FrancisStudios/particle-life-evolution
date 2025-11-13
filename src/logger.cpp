/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#include "./h/logger.h"

#define ERROR "[ERROR]"
#define LOG "[LOG]"
#define WARN "[WARN]"

bool isLoggerOn = false;

Logger &Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::turnOnLogger()
{
    this->isLoggerOn = true;
}

void Logger::turnOffLogger()
{
    this->isLoggerOn = false;
}

void Logger::toggleLogger()
{
    this->isLoggerOn = !this->isLoggerOn;
}

void Logger::print(const char buffer[], int logLevel)
{
    const char *logLevelPrefix = nullptr;

    // Determine the log level prefix
    switch (logLevel)
    {
    case 1:
        logLevelPrefix = LOG;
        break;
    case 2:
        logLevelPrefix = WARN;
        break;
    case 3:
        logLevelPrefix = ERROR;
        break;
    default:
        logLevelPrefix = LOG;
        break;
    }

    printf("%s %s\n", logLevelPrefix, buffer);
}
