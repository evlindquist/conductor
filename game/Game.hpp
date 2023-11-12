#pragma once

#include "game/board/Board.hpp"
#include "game/board/Route.hpp"
#include "game/board/Train.hpp"

#include "game/board/Player.hpp"

#include "game/types/Types.hpp"
#include "game/types/Turn.hpp"
#include "game/types/PlayerId.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

class Game
{
    using PlayersT = std::vector<Player>;

    std::size_t theTurnTracker;

    Board theBoard;
    PlayersT thePlayers;

public:
    Game() = delete;

    Game(std::size_t aNumberOfPlayers) :
        theBoard{},
        thePlayers{Player{PlayerId::One}},
        theTurnTracker{0}
    {
        // for (std::uint8_t i = 0; i < aNumberOfPlayers; i++)
        // {
        //     thePlayers.push_back(Player{static_cast<PlayerId>(i)});
        // }
    }

    PlayerId play()
    {
        // while (1 != 0)
        // {
            takeTurn();

            if (thePlayers.at(0).numberTrains() <= 2)
            {
                // break;
            }

            endTurn();
        // }

        for (std::size_t i = 0; i < thePlayers.size(); i++)
        {
            takeTurn();
            endTurn();
        }

        return endGame();

        return PlayerId::One;
    }

private:
    void takeTurn()
    {
        switch (thePlayers.at(0).takeTurn())
        {
            case Turn::DrawDestinationTickets:
                drawDestinationTickets(1);
                break;
            case Turn::DrawTrains:
                drawTrains();
                break;
            case Turn::PlaceTrains:
                claimRoute();
                break;
        }
    }

    void endTurn()
    {
        // theTurnTracker = (theTurnTracker + 1) % thePlayers.size();
    }

    PlayerId endGame()
    {
        PlayerId theWinningPlayer = PlayerId::None;
        PointsT theHighestPoints = 0;
        for (auto& myPlayer : thePlayers)
        {
            PointsT myPlayersPoints = myPlayer.tallyPoints();
            if (myPlayersPoints > theHighestPoints)
            {
                theHighestPoints = myPlayersPoints;
                theWinningPlayer = myPlayer.id();
            }
        }

        return theWinningPlayer;
    }

    void drawDestinationTickets(std::size_t aNumberToChoose)
    {
        DestinationsT myReturnedDestinations = thePlayers.at(0).drawDestinationTickets(theBoard.destinationTickets(), aNumberToChoose);
        theBoard.returnDestinations(myReturnedDestinations);
    }

    void drawTrains()
    {
        for (std::size_t i = 0; i < 2; i++)
        {
            TrainChoice myChoice = thePlayers.at(0).chooseTrain(i, theBoard.trains());
            Train myTrain = theBoard.drawTrain(myChoice);
            thePlayers.at(0).acceptTrain(myTrain);

            if (myChoice != TrainChoice::TopDeck && myTrain.color() == Color::Rainbow)
            {
                break;
            }
        }
    }

    void claimRoute()
    {
        TrainsT myReturnedTrains = thePlayers.at(0).claimRoute(theBoard.routes());
        theBoard.returnTrains(myReturnedTrains);
    }
};