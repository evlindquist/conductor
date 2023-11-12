#pragma once

#include "game/types/Types.hpp"
#include "game/types/Color.hpp"
#include "game/types/PlayerId.hpp"

#include <stdexcept>

class Route
{
    const CityPairT theCities;
    const ColorPairT theColors;
    const LengthT theLength;

    PlayerId thePlayer{PlayerId::None};

    Route() = delete;

public:
    Route(City aFirstCity, City aSecondCity, Color aFirstColor, Color aSecondColor, LengthT aLength) :
        theCities{std::make_pair(aFirstCity, aSecondCity)},
        theColors{std::make_pair(aFirstColor, aSecondColor)},
        theLength{aLength}
    {
    }

    CityPairT cities() const
    {
        return theCities;
    }

    ColorPairT colors() const
    {
        return theColors;
    }

    LengthT length() const
    {
        return theLength;
    }

    bool claimable() const
    {
        return thePlayer == PlayerId::None;
    }

    void claim(PlayerId aPlayer)
    {
        if (claimable())
        {
            thePlayer = aPlayer;
        }
        else
        {
            throw std::runtime_error("This route has already been claimed");
        }
    }

    PointsT points() const 
    {
        switch (theLength)
        {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 4;
            case 4:
                return 7;
            case 5:
                return 10;
            case 6:
                return 15;
        }

        throw std::runtime_error("Trains can only have length 1-6");
    }
};