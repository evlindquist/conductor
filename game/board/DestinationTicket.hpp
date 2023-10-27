#pragma once

#include "game/types/Types.hpp"
#include "game/types/City.hpp"

#include <utility>

class DestinationTicket
{
public:
    using PointsT = std::uint32_t;
    using CityPairT = std::pair<City, City>;

    CityPairT theCities;
    PointsT thePoints;

    DestinationTicket()
    {
    }

    DestinationTicket(City aFirstCity, City aSecondCity, PointsT aPoints) : 
        theCities{std::make_pair(aFirstCity, aSecondCity)},
        thePoints{aPoints}
    {
    }
};

static constexpr std::size_t NUM_DESTINATION_TICKETS = 30;

const std::array<DestinationTicket, NUM_DESTINATION_TICKETS> theDestionationsList = {
    DestinationTicket{City::Montreal,       City::Atlanta,      9},
    DestinationTicket{City::LosAngeles,     City::NewYork,      21},
    DestinationTicket{City::SanFrancisco,   City::Atlanta,      17},
    DestinationTicket{City::Boston,         City::Miami,        12},
    DestinationTicket{City::Atlanta,        City::NewYork,      6},
    DestinationTicket{City::Vancouver,      City::SantaFe,      13},
    DestinationTicket{City::Winnipeg,       City::LittleRock,   11},
    DestinationTicket{City::Denver,         City::ElPaso,       4},
    DestinationTicket{City::Seattle,        City::NewYork,      22},
    DestinationTicket{City::KansasCity,     City::Houston,      5},
    DestinationTicket{City::LosAngeles,     City::Helena,       8},
    DestinationTicket{City::SaultStMarie,   City::OklahomaCity, 9},
    DestinationTicket{City::Calgary,        City::SaltLakeCity, 7},
    DestinationTicket{City::Denver,         City::Pittsburgh,   11},
    DestinationTicket{City::Chicago,        City::SantaFe,      9},
    DestinationTicket{City::LosAngeles,     City::Miami,        20},
    DestinationTicket{City::Duluth,         City::Houston,      8},
    DestinationTicket{City::Chicago,        City::NewOrleans,   7},
    DestinationTicket{City::LosAngeles,     City::Chicago,      16},
    DestinationTicket{City::Winnipeg,       City::Houston,      12},
    DestinationTicket{City::Dallas,         City::NewYork,      11},
    DestinationTicket{City::Montreal,       City::NewOrleans,   13},
    DestinationTicket{City::Calgary,        City::Phoenix,      13},
    DestinationTicket{City::Portland,       City::Phoenix,      11},
    DestinationTicket{City::SaultStMarie,   City::Nashville,    8},
    DestinationTicket{City::Toronto,        City::Miami,        10},
    DestinationTicket{City::Portland,       City::Nashville,    17},
    DestinationTicket{City::Duluth,         City::ElPaso,       10},
    DestinationTicket{City::Vancouver,      City::Montreal,     20},
    DestinationTicket{City::Seattle,        City::LosAngeles,   9}
};