/**
 *  ------ [ Property of Francis Studios ] ------
 * ==============================================
 * This is an open source project, feel free to use
 * .. github:https://github.com/francisstudios ..
 * ____ ©2025 Francis Studios Softwares by L. ___
 */

#ifndef UTIL_H
#define UTIL_H
#pragma once

#include <string>
#include <sstream>

namespace Util
{
    std::string WINDOW_TITLE();
    template <typename C>
    inline int strcpy_s(C *d, unsigned long dmax, const C *s);
};
#endif