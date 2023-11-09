#pragma once

#include "game/board/DestinationTicket.hpp"
#include "game/types/Color.hpp"
#include "game/types/Turn.hpp"
#include "game/board/Route.hpp"
#include "game/board/Train.hpp"
#include "game/types/Types.hpp"

#include <array>
#include <cstdint>
#include <vector>

class Player
{
    using NumberTrainsT = std::uint32_t;

    using TrainsT = std::array<NumberTrainsT, NUM_TRAIN_COLORS>;

    PlayerId thePlayerId;

    PointsT thePoints;
    NumberTrainsT theNumberTrains;

    DestinationsT theDestinations;
    TrainsT theTrains;

    std::vector<City> theCitiesInNetwork;

public:
    Player(PlayerId aPlayerId) :
        thePlayerId{aPlayerId},
        thePoints{0},
        theNumberTrains{0},
        theDestinations{},
        theTrains{},
        theCitiesInNetwork{}
    {
    }

    Turn takeTurn()
    {
        return Turn::DrawTrains;
    }

    DestinationsT drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose)
    {
        return DestinationsT{};
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

    Route& claimRoute(RoutesT aRoutes)
    {
        // Route myRoute = theStrategy.claimRoute();

        Route& myRoute = aRoutes.at(0);

        if (!myRoute.claimable())
        {
            throw std::runtime_error("Trying to claim already claimed route");
        }

        myRoute.claim(thePlayerId);

        theCitiesInNetwork.push_back(myRoute.cities().first);
        theCitiesInNetwork.push_back(myRoute.cities().second);

        increaseScore(myRoute.points());

        return myRoute;
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