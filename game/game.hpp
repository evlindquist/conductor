#pragma once

#include "game/types/Types.hpp"

#include "game/board/Board.hpp"
#include "game/board/Route.hpp"
#include "game/gameState/Player.hpp"

#include "game/board/Train.hpp"
#include "game/board/DestinationTicket.hpp"

#include "game/types/Turn.hpp"

#include <fstream>
#include <iostream>
#include <vector>

class Game
{
    using PlayersT = std::vector<Player>;

    Board theBoard;
    PlayersT thePlayers;

    struct TurnTracker
    {
        std::uint32_t theTurnTracker;
        std::size_t theNumberOfPlayers;

        TurnTracker(std::size_t aNumberOfPlayers) :
            theTurnTracker{0},
            theNumberOfPlayers{aNumberOfPlayers}
        {
        }

        void next()
        {
            theTurnTracker = (theTurnTracker + 1) % theNumberOfPlayers;
        }
    };
    TurnTracker theTurnTracker;

    Player& theTurnTaker;

public:
    Game() :
        theBoard{},
        thePlayers{Player{}},
        theTurnTracker{thePlayers.size()},
        theTurnTaker{thePlayers.at(theTurnTracker.theTurnTracker)}
    {
    }

    void play()
    {
        startGame();

        // while (1 != 0)
        // {
        //     next();

        //     if (theTurnTaker.numberTrains() <= 2)
        //     {
        //         break; // TODO: need to add one more turn for each player once trian threshold hit
        //     }

        //     theTurnTracker.next();
        // }

        // endGame();
    }

private:
    void startGame()
    {
        // for (std::size_t i = 0; i < thePlayers.size(); i++)
        // {
        //     theTurnTaker = thePlayers.at(theTurnTracker.theTurnTracker);
        //     drawDestinationTickets(2);
        //     theTurnTracker.next();
        // }
    }

    void next()
    {
        theTurnTaker = thePlayers.at(theTurnTracker.theTurnTracker);

        switch (theTurnTaker.takeTurn())
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

    void endGame()
    {
        std::for_each(thePlayers.begin(), thePlayers.end(), [](Player& aPlayer) { aPlayer.tallyPoints(); } );
    }

    void drawDestinationTickets(std::size_t aNumberToChoose)
    {
        theTurnTaker.drawDestinationTickets(theBoard.drawDestinationTickets(), aNumberToChoose);
    }

    void drawTrains()
    {
        for (std::size_t i = 0; i < 2; i++)
        {
            TrainChoice myChoice = theTurnTaker.chooseTrain(i, theBoard.trains());
            Train myTrain = theBoard.drawTrain(myChoice);
            theTurnTaker.acceptTrain(myTrain);

            if (myChoice != TrainChoice::TOP_DECK && myTrain.color() == Color::Rainbow)
            {
                break;
            }
        }
    }

    void claimRoute()
    {
        theTurnTaker.claimRoute(theBoard.routes());       
    }
};