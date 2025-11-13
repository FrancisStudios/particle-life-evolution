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

Logger &log = Logger::getInstance();

namespace JSONOps
{
    void load_json_file(const std::string &filepath)
    {
        std::ifstream f(filepath);

        if (f.is_open())
        {
            try
            {
                json data = json::parse(f);
                if (data.contains("file"))
                {
                    std::string value = data["file"];
                }
            }
            catch (json::parse_error &e)
            {
                log.print(CAN_NOT_PARSE_FILE, 3);
            }
        }
        else
        {
            log.print(CAN_NOT_OPEN_FILE, 3);
        }
    }
}