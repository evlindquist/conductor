#pragma once

#include "game/board/destinations/DestinationTicket.hpp"
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
        return Turn::DrawTrains;
    }

    void drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose)
    {
    }

    TrainChoice drawTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions, Train aTopDeck)
    {
        // Train myTrain = theStrategy.drawTrain(aChoiceNumber, aOptions, aTopDeck);
        // theTrains.at(static_cast<std::uint8_t>(0)) += 1;
        
        return TrainChoice::TOP_DECK;
    }

    Route claimRoute()
    {
        // Route myRoute = theStrategy.claimRoute();
        // increaseScore(myRoute.points());

        // return myRoute;

        return Route{0, Color::Blue};
    }

    void increaseScore(PointsT aPoints)
    {
        thePoints += aPoints;
    }

    PointsT tallyPoints()
    {
        return 0;
    }

    NumberTrainsT numberTrains()
    {
        return theNumberTrains;
    }
};