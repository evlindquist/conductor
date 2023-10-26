#pragma once

#include "game/types/City.hpp"

#include <utility>

class DestinationTicket
{
public:
    using RouteT = std::pair<City, City>;
    using PointsT = std::uint32_t;

    RouteT theRoute;
    PointsT thePoints;

    DestinationTicket()
    {
    }

    DestinationTicket(City aFirstCity, City aSecondCity, PointsT aPoints) : 
        theRoute{std::make_pair(aFirstCity, aSecondCity)},
        thePoints{aPoints}
    {
    }
};