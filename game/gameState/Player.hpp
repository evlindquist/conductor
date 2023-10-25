#pragma once

#include "game/destinations/DestinationTicket.hpp"
#include "game/types/Color.hpp"

#include <array>
#include <cstdint>
#include <vector>

class Player
{
    using ScoreT = std::uint32_t;
    using NumberTrainsT = std::uint32_t;

    using DestinationsT = std::vector<DestinationTicket>;
    using TrainsT = std::array<Color, NUM_TRAIN_COLORS>;

    ScoreT theScore;
    NumberTrainsT theNumberTrains;

    DestinationsT theDestinations;
    TrainsT theTrains;

    // how do we implemeent routes / cities in network?
};