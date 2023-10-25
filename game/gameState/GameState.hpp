#pragma once

#include <game/board/Board.hpp>
#include <game/gameState/Player.hpp>

#include "game/board/Train.hpp"
#include "game/board/destinations/DestinationTicket.hpp"

#include <vector>

class GameState
{
    using PlayersT = std::vector<Player>;
    using TrainsT = std::vector<Train>;
    using DestinationsT = std::vector<DestinationTicket>;

    Board theBoard;
    PlayersT thePlayers;

    DestinationsT theDestinationsDeck;
    TrainsT theTrainDeck;
    TrainsT theRevealedTrains;

    GameState() :
        theBoard{}
    {

    }
}