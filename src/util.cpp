/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */
#include "./h/util.h"

#define APP_NAME "Particle Life"
#define APP_VERSION "v0.0.1"
#define AUTHOR "by FrancisStudios"
#define SPACING " "
#define DIVIDER " | "

#ifdef _WIN32
#define OS "for Windows"
#elif __linux__
#define OS "for Linux"
#endif

namespace Util
{
    std::string WINDOW_TITLE()
    {
        std::ostringstream windowTitle;
        windowTitle << APP_NAME
                    << SPACING
                    << APP_VERSION
                    << SPACING
                    << OS
                    << DIVIDER
                    << AUTHOR;

        return windowTitle.str();
    }

    template <typename C>
    inline int strcpy_s(C *d, unsigned long dmax, const C *s)
    {
        if (dmax <= 1 || !d)
        {
            if (!d || !dmax)
                return 22;
            *d = C(0);
            return 0;
        }
        for (C *de = d + dmax - 1; (d != de || (*d = C(0))) && (*d = *s); ++d, ++s)
            ;
        return 0;
    }
}