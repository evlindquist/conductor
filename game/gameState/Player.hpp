#pragma once

#include "game/destinations/DestinationTicket.hpp"
#include "game/types/Color.hpp"
#include "game/types/Turn.hpp"

#include <array>
#include <cstdint>
#include <vector>

class Player
{
    using NumberTrainsT = std::uint32_t;

    using TrainsT = std::array<Color, NUM_TRAIN_COLORS>;

    PointsT thePoints;
    NumberTrainsT theNumberTrains;

    DestinationsT theDestinations;
    TrainsT theTrains;

    // how do we implemeent routes / cities in network?

public:
    Turn takeTurn()
    {
    }

    void drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose)
    {
    }

    TrainChoice drawTrain(std::size_t aChoiceNumber, TrainOptionsT aOptions, Train aTopDeck)
    {
    }

    Route claimRoute()
    {
    }

    void increaseScore(PointsT aPoints)
    {
        thePoints += aPoints;
    }

    PointsT tallyPoints()
    {
    }
};