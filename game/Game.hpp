#pragma once

#include "game/types/Types.hpp"

#include "game/board/Board.hpp"
#include "game/board/Route.hpp"
#include "game/board/Player.hpp"

#include "game/board/Train.hpp"

#include "game/types/Turn.hpp"

#include <fstream>
#include <iostream>
#include <vector>

class Game
{
    using PlayersT = std::vector<Player>;

    Board theBoard;
    PlayersT thePlayers;

    PlayersT::iterator theTurnTaker;

public:
    Game(std::size_t aNumberOfPlayers) :
        theBoard{},
        thePlayers{},
        theTurnTaker{thePlayers.begin()}
    {
        for (std::size_t i = 0; i < aNumberOfPlayers; i++)
        {
            thePlayers.push_back(Player{static_cast<PlayerId>(i)});
        }
    }

    PlayerId play()
    {
        while (1 != 0)
        {
            takeTurn();

            if (theTurnTaker->numberTrains() <= 2)
            {
                break;
            }

            endTurn();
        }

        for (std::size_t i = 0; i < thePlayers.size(); i++)
        {
            takeTurn();
            endTurn();
        }

        return endGame();
    }

private:
    void takeTurn()
    {
        switch (theTurnTaker->takeTurn())
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
        theTurnTaker++;
        if (theTurnTaker == thePlayers.end())
        {
            theTurnTaker = thePlayers.begin();
        }
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
        DestinationsT myReturnedDestinations = theTurnTaker->drawDestinationTickets(theBoard.destinationTickets(), aNumberToChoose);
        theBoard.returnDestinations(myReturnedDestinations);
    }

    void drawTrains()
    {
        for (std::size_t i = 0; i < 2; i++)
        {
            TrainChoice myChoice = theTurnTaker->chooseTrain(i, theBoard.trains());
            Train myTrain = theBoard.drawTrain(myChoice);
            theTurnTaker->acceptTrain(myTrain);

            if (myChoice != TrainChoice::TOP_DECK && myTrain.color() == Color::Rainbow)
            {
                break;
            }
        }
    }

    void claimRoute()
    {
        TrainsT myReturnedTrains = theTurnTaker->claimRoute(theBoard.routes());
        theBoard.returnTrains(myReturnedTrains);
    }
};