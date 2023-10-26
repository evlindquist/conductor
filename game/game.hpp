#pragma once

#include "game/types/Types.hpp"

#include "game/board/Board.hpp"
#include "game/board/Route.hpp"
#include "game/gameState/Player.hpp"

#include "game/board/Train.hpp"
#include "game/board/destinations/DestinationTicket.hpp"

#include "game/types/Turn.hpp"

#include <vector>

class Game
{
    using PlayersT = std::vector<Player>;

    Board theBoard;
    PlayersT thePlayers;

    DestinationsT theDestinationsDeck;
    TrainsDeckT theTrainsDeck;

    TurnTracker theTurnTracker;

    Player& theTurnTaker;

public:
    Game() :
        theBoard{}
        theTurnTracker{}
    {
        theTurnTaker = thePlayers.at(theTurnTracker.theTurnTracker);
    }

    void play()
    {
        startGame();

        while (1 != 0)
        {
            next();

            if (theTurnTaker.numberTrains() <= 2)
            {
                break; // TODO: need to add one more turn for each player once trian threshold hit
            }

            theTurnTracker.next();
        }

        endGame();
    }

private:
    void startGame()
    {
        for (std::size_t i = 0; i < thePlayers.size(); i++)
        {
            theTurnTaker = thePlayers.at(theTurnTracker.theTurnTracker);
            drawDestinationTickets(2);
            theTurnTracker.next();
        }
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
            case turn::PlaceTrains:
                claimRoute();
                break;
        }
    }

    void endGame()
    {
        std::for_each(thePlayers.begin(), thePlayers.end(), [](Player& aPlayer) {aPlayer.tallyPoints()} );
    }

    void drawDestinationTickets(std::size_t aNumberToChoose)
    {
        DestinationOptionsT myOptions{};
        for (std::size_t i = 0; i < myOptions.size(); i++)
        {
            myOptions.at(i) = theDestinationsDeck.back();
            theDestinationsDeck.pop_back();
        }

        theTurnTaker.drawDestinationTickets(myOptions, aNumberToChoose);
    }

    void drawTrains()
    {
        TrainOptionsT myOptions{};
        for (std::size_t i = 0; i < myOptions.size(); i++)
        {
            myOptions.at(i) = theTrainsDeck.back();
            theTrainsDeck.pop_back();
        }

        for (std::size_t i = 0; i < 2; i++)
        {
            TrainChoice myChoice = theTurnTaker.drawTrain(i, myOptions, theTrainsDeck.back()); // don't send in  top deck, bad for security reasons
            
            if (myChoice == TOP_DECK)
            {
                theTrainsDeck.pop_back();
            }
            else
            {
                Color myTrainColor = theTrainOptions.at(static_cast<std::uint8_t>(myChoice)).color();

                theTrainOptions.at(static_cast<std::uint8_t>(myChoice)) = theTrainsDeck.back();
                theTrainsDeck.pop_back();

                if (myTainColor == Color::Rainbow)
                {
                    break;
                }
            }
        }
        
        theTrainsDeck.insert(theTrainsDeck.end(), myChoices.begin(), myChoices.end());
    }

    void claimRoute()
    {
        Route myRoute = theTurnTaker.claimRoute();
        PointsT myPoints = theBoard.claimRoute(myRoute, theTurnTaker);
       
        theTurnTaker.increaseScore(myPoints);
    }

    struct TurnTracker
    {
        std::uint32_t theTurnTracker;

        TurnTracker() : theTurnTracker{0}
        {
        }

        void next()
        {
            theTurnTracker++ % thePlayers.size();
        }
    };
}