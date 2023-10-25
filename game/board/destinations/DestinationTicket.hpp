#pragma once

#include "game/types/City.hpp"

class DestinationTicket
{
public:
    using RouteT = std::pair<City, City>;
    using PointsT = std::uint32_t;

    RouteT theRoute;
    PointsT thePoints;

    DestinationTicket() = delete;

    DestinationTicket(City aFirstCity, City aSecondCity, PointsT aPoints) : 
        theRoute{std::make_pair<City, City>(aFirst, aSecondCity)},
        thePoints{aPoints}
    {
    }
};