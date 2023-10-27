#pragma once

#include "game/types/Types.hpp"

#include "game/board/Board.hpp"
#include "game/board/Route.hpp"
#include "game/gameState/Player.hpp"

#include "game/board/Deck.hpp"
#include "game/board/Train.hpp"
#include "game/board/DestinationTicket.hpp"

#include "game/types/Turn.hpp"

#include <fstream>
#include <iostream>
#include <vector>

static constexpr std::size_t NUM_TRAINS_PER_COLOR = 12;
static constexpr std::size_t NUM_RAINBOW_TRAINS = 14;

class Game
{
    using PlayersT = std::vector<Player>;

    Board theBoard;
    PlayersT thePlayers;

    Deck<DestinationTicket> theDestinationsDeck;
    Deck<Train> theTrainsDeck;

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
        initializeDecks();

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

    void initializeDecks()
    {
        for (std::size_t i = 0; i < NUM_TRAIN_COLORS; i++)
        {
            for (std::size_t j = 0; j < NUM_TRAINS_PER_COLOR; j++)
            {
                theTrainsDeck.push_back(Train{static_cast<Color>(i)});
            }
        }
        theTrainsDeck.push_back(Train{Color::Rainbow});
        theTrainsDeck.push_back(Train{Color::Rainbow});
        theTrainsDeck.shuffle();

        theDestinationsDeck.insert(theDestionationsList);
        theDestinationsDeck.shuffle();
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
            
            if (myChoice == TrainChoice::TOP_DECK)
            {
                theTrainsDeck.pop_back();
            }
            else
            {
                Color myTrainColor = myOptions.at(static_cast<std::uint8_t>(myChoice)).color();

                myOptions.at(static_cast<std::uint8_t>(myChoice)) = theTrainsDeck.back();
                theTrainsDeck.pop_back();

                if (myTrainColor == Color::Rainbow)
                {
                    break;
                }
            }
        }
        
        theTrainsDeck.insert(myOptions);
    }

    void claimRoute()
    {
        Route myRoute = theTurnTaker.claimRoute();
        PointsT myPoints = theBoard.claimRoute(myRoute, theTurnTaker);
       
        theTurnTaker.increaseScore(myPoints);
    }
};