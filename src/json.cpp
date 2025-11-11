/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#define VALID_CONFIGURATION_VERSION "ple-simconfig-1.x"

#include "./h/json.h"

using json = nlohmann::json;

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
                // Handle parsing errors
            }
        }
        else
        {
            // Handle cannot open file
        }
    }
}