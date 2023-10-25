#pragma once

#include "game/types/Color.hpp"

class Route
{
    using LengthT = std::uint32_t;

    LengthT theLength;
    Color theColor;

    Route() = delete;

    Route(LengthT aLength, Color aColor) :
        theLength{aLength},
        theColor{aColor}
    {
    }
};