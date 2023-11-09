#pragma once

#include "game/board/DestinationTicket.hpp"
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

    std::vector<City> theCitiesInNetwork{};

public:
    Player() :
        thePoints{0},
        theNumberTrains{0},
        theDestinations{},
        theTrains{}
    {
    }

    Turn takeTurn()
    {
        return Turn::DrawTrains;
    }

    void drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose)
    {
    }

    TrainChoice chooseTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions)
    {
        // return theStrategy.drawTrain(aChoiceNumber, aOptions, aTopDeck);
        
        return TrainChoice::TOP_DECK;
    }

    void acceptTrain(Train aTrain)
    {
        theTrains.at(static_cast<std::size_t>(aTrain.color())) += 1;
    }

    Route claimRoute(RoutesT aRoutes)
    {
        // Route myRoute = theStrategy.claimRoute();
        // increaseScore(myRoute.points());

        // return myRoute;

        return aRoutes[0];
    }

    void increaseScore(PointsT aPoints)
    {
        thePoints += aPoints;
    }

    PointsT tallyPoints()
    {
        return thePoints;
    }

    NumberTrainsT numberTrains()
    {
        return theNumberTrains;
    }
};