#pragma once

#include "game/board/DestinationTicket.hpp"
#include "game/types/Color.hpp"
#include "game/types/Turn.hpp"
#include "game/board/Route.hpp"
#include "game/board/Train.hpp"
#include "game/types/Types.hpp"

#include <array>
#include <cstdint>
#include <variant>
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
        // DestinationChoiceT myChoices = theStrategy.drawDestinationTickets(aOptions);
        DestinationChoiceT myChoices = DestinationChoiceT{true, true, true};

        DestinationsT myReturnedDestinations{};

        for (std::size_t i = 0; i < aOptions.size(); i++)
        {
            if (keepDestination(myChoices, i))
            {
                theDestinations.push_back(aOptions.at(i));
            }
            else
            {
                myReturnedDestinations.push_back(aOptions.at(i));
            }
        }

        if (aOptions.size() - myReturnedDestinations.size() < aNumberToChoose)
        {
            throw std::runtime_error("too few destinations kept.");
        }

        return myReturnedDestinations;
    }

    TrainChoice chooseTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions)
    {
        // TrainChoice myChoice = theStrategy.drawTrain(aChoiceNumber, aOptions, aTopDeck);
        TrainChoice myChoice = TrainChoice::TOP_DECK;

        if (aChoiceNumber != 0 && myChoice != TrainChoice::TOP_DECK)
        {
            if (aOptions.at(static_cast<std::size_t>(myChoice)).color() == Color::Rainbow)
            {
                throw std::runtime_error("You cannot choose a rainbow train on second train choice");
            }
        }
        
        return myChoice;
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

    bool keepDestination(DestinationChoiceT aChoices, std::size_t aIndex)
    {
        switch(aIndex)
        {
            case 0:
                return std::get<0>(aChoices);
            case 1:
                return std::get<1>(aChoices);
            case 2:
                return std::get<2>(aChoices);
            default:
                throw std::runtime_error("cannot have more than three choices");
        }
    }
};