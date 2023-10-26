#pragma once

#include "game/destinations/DestinationTicket.hpp"
#include "game/types/Color.hpp"
#include "game/types/Turn.hpp"
#include "game/board/Route.hpp"
#include "game/board/Train.hpp"

#include <array>
#include <cstdint>
#include <vector>

class Player
{
    using NumberTrainsT = std::uint32_t;

    using TrainsT = std::array<NumberTrainsT, NUM_TRAIN_COLORS>;

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

    TrainChoice drawTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions, Train aTopDeck)
    {
        Train myTrain = theStrategy.drawTrain(aChoiceNumber, aOptions, aTopDeck);
    
        theTrains.at(staic_cast<std::uint8_t>(myTrain)) += 1;
    }

    Route claimRoute()
    {
        Route myRoute = theStrategy.claimRoute();
        increaseScore(myRoute.points());

        return myRoute;
    }

    void increaseScore(PointsT aPoints)
    {
        thePoints += aPoints;
    }

    PointsT tallyPoints()
    {
    }
};