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

void Logger::print(char *buffer[], int logLevel)
{
    char *logLevelIndicator[8];
    switch (logLevel)
    {
    case 1:
        // Util::strcpy_s(logLevelIndicator, LOG, sizeof(LOG));
        break;
    case 2:
        // logLevelIndicator = WARN;
        break;
    case 3:
        // logLevelIndicator = ERROR;
        break;
    default:
        // logLevelIndicator = LOG;
        break;
    }

    printf("%s", logLevelIndicator);
}
