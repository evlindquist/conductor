#pragma once

#include "strategy/StrategyBase.hpp"

class HumanStrategy : public StrategyBase
{
public:
    DestinationChoiceT drawDestinationTickets(DestinationOptionsT aOptions, std::size_t aNumberToChoose) override
    {
        return DestinationChoiceT{true, true, true};
    }

    TrainChoice chooseTrain(std::size_t aChoiceNumber, const TrainOptionsT aOptions) override
    {
        return TrainChoice::TOP_DECK;
    }

    ClaimedRoute claimRoute(RoutesT aRoutes) override
    {
        return ClaimedRoute{aRoutes.at(0), aRoutes.at(0).colors().first};
    }

};