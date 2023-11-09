#pragma once

#include <array>

using PointsT = std::uint16_t;

#include "game/types/City.hpp"
using CityPairT = std::pair<City, City>;

#include "game/board/DestinationTicket.hpp"
using DestinationsT = std::vector<DestinationTicket>;
using DestinationOptionsT = std::array<DestinationTicket, 3>;

#include "game/board/Train.hpp"
using TrainsDeckT = std::vector<Train>;
using TrainOptionsT = std::array<Train, 5>;

#include "game/board/Route.hpp"
static constexpr std::size_t NUM_ROUTES = 78;
using RoutesT = const std::array<Route, NUM_ROUTES>;