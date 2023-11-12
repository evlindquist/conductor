#pragma once

#include "game/types/Types.hpp"
#include "game/types/Turn.hpp"
#include "game/types/ClaimedRoute.hpp"

class StrategyBase
{
public:
    virtual DestinationChoiceT drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose)
    {
        throw std::runtime_error("StrategyBase needs to have its virtual functions override");
    }

    virtual TrainChoice chooseTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions)
    {
        throw std::runtime_error("StrategyBase needs to have its virtual functions override");
    }

    virtual ClaimedRoute claimRoute(RoutesT aRoutes)
    {
        throw std::runtime_error("StrategyBase needs to have its virtual functions override");
    }
};