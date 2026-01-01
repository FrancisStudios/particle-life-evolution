/**
 * ┌──────────────────────────────────────────┐
 * │   FRANCIS STUDIOS SOFTWARE  |    2026    │
 * ├──────────────────────────────────────────┤
 * │  OSS Project : Open for use & remix      │
 * │  GitHub      : github.com/francisstudios │
 * │  Author      : © Francis Studios by L.   │
 * └──────────────────────────────────────────┘
 */

#include "./h/background.h"

namespace Background
{
    void draw(sf::RenderWindow &window)
    {
        const sf::Color clearColor(0x00, 0x1a, 0x33);

        window.clear(clearColor);
    }
}