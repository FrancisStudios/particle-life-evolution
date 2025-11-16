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
#define CONFIG_FILE_ACCEPT "Config file version accepted"
#define CONFIG_FILE_DENY "Invalid config file version"
#define INVALID_SPECIES_COUNT "Species count can range between 2 and 8"

#include "./h/json.h"

using json = nlohmann::json;

Logger &logger = Logger::getInstance();
SimConfig &simulationConfig = SimConfig::getInstance();

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
                    std::string fileVersion = data["file"];
                    if (strcmp(fileVersion.c_str(), VALID_CONFIGURATION_VERSION) == 0)
                    {
                        logger.print(CONFIG_FILE_ACCEPT, 1);

                        float _particleSize = (float)data["particle-size"];
                        float _speciesCount = (int)data["species-count"];

                        if (isSpeciesCountValid(_speciesCount))
                        {
                            simulationConfig.setParticleSize(_particleSize);
                            printf("species name: %s\n", ((std::string)data["species"][0]["name"]).c_str());
                        }
                        else
                        {
                            logger.print(INVALID_SPECIES_COUNT, 3);
                        }
                    }
                    else
                    {
                        logger.print(CONFIG_FILE_DENY, 3);
                    }
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

     bool isSpeciesCountValid(int SC)
    {
        return (SC >= 2) && (SC <= 8);
    }
}