/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

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
                // Read directly from the file stream
                json data = json::parse(f);
                // Or use the stream operator, which also works for file streams:
                // json data;
                // f >> data;

                // Example access:
                if (data.contains("key_name"))
                {
                    std::string value = data["key_name"];
                    // ... use value
                }
            }
            catch (json::parse_error &e)
            {
                // Handle parsing errors
                //std::cerr << "JSON parse error: " << e.what() << std::endl;
            }
        }
        else
        {
            //std::cerr << "Could not open file: " << filepath << std::endl;
        }
    }
}