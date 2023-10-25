#pragma once

#include "game/board/Node.hpp"
#include "game/board/Route.hpp"

class Board
{
    using NodesT = std::vector<Node>;
    using RoutesT = std::vector<Route>;

    NodesT theNodes;
    RoutesT theRoutes;

    Board()
    {
        // lot to do in here
    }

    PointsT claimRoute()
    {
    }
};