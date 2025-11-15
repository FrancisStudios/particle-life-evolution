/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#define VALID_CONFIGURATION_VERSION "ple-simconfig-1.x"

#define CAN_NOT_PARSE_FILE "Parsing error while reading JSON file! (json.cpp)"
#define CAN_NOT_OPEN_FILE "Can not open JSON file! (json.cpp)"

#include "./h/json.h"

using json = nlohmann::json;

Logger &logger = Logger::getInstance();

namespace JSONOps
{
    void loadSimulatorConfig(const std::string &filepath)
    {
        std::ifstream file(filepath);

        if (file.is_open())
        {
            try
            {
                json data = json::parse(file);
                if (data.contains("file"))
                {
                    std::string value = data["file"];
                    logger.print(value.c_str());
                }
            }
            catch (json::parse_error &e)
            {
                logger.print(CAN_NOT_PARSE_FILE, 3);
            }
        }
        else
        {
            logger.print(CAN_NOT_OPEN_FILE, 3);
        }
    }
}