#pragma once

#include <array>

using PointsT = std::uint16_t;

using DestinationsT = std::vector<DestinationTicket>;
using DestinationOptionsT = std::array<DestinationTicket, 3>;

using TrainsDeckT = std::vector<Train>;
using TrainOptionsT = std::array<Train, 5>;