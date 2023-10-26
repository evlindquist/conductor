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

    PointsT points()
    {
        switch (theLength)
        {
            case 1:
                return 1;
            case 2:
                return 2:
            case 3:
                return 4;
            case 4:
                return 7;
            case 5:
                return 10;
            case 6:
                return 15;
        }
    }
};