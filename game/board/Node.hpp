#pragma once

#include "game/types/City.hpp"
#include "game/board/Route.hpp"

class Node
{
    using ContainerT = std::vector<Route*>;

    City theCity;
    ContainerT theRoutes;

public:
    Node() = delete;

    Node(City aCity) : 
        theCity{aCity},
        theRoutes{}
    {
    }

    void addRoute(Route* aRoutePointer)
    {
        theRoutes.push_back(aRoutePointer);
    }
};