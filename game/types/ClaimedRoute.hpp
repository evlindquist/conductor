#pragma once

#include "game/board/Route.hpp"
#include "game/types/Color.hpp"

class ClaimedRoute
{
    const Route& theRoute;
    const Color theColor;

    ClaimedRoute() = delete;

public:
    ClaimedRoute(Route& aRoute, Color aColor) :
        theRoute{aRoute},
        theColor{aColor}
    {
    }

    Route route() const
    {
        return theRoute;
    }
    
    LengthT length() const
    {
        return theRoute.length();
    }

    Color color() const
    {
        return theColor;
    }

    PointsT points() const
    {
        return theRoute.points();
    }

    CityPairT cities() const
    {
        return theRoute.cities();
    }
};