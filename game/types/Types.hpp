#pragma once

#include <array>
#include <tuple>
#include <vector>

using PointsT = std::uint16_t;
using LengthT = std::uint32_t;
using NumberTrainsT = std::uint32_t;

#include "game/types/City.hpp"
#include "game/types/Color.hpp"
using CityPairT = std::pair<City, City>;
using ColorPairT = std::pair<Color, Color>;

#include "game/board/DestinationTicket.hpp"
using DestinationsT = std::vector<DestinationTicket>;
using DestinationOptionsT = std::array<DestinationTicket, 3>;
using DestinationChoiceT = std::tuple<bool, bool, bool>;

#include "game/board/Train.hpp"
using TrainsT = std::vector<Train>;
using TrainOptionsT = std::array<Train, 5>;

#include "game/board/Route.hpp"
static constexpr std::size_t NUM_ROUTES = 78;
using RoutesT = std::array<Route, NUM_ROUTES>;