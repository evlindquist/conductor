#pragma once

#include <cstdint>

enum class Turn : std::uint8_t
{
    DrawDestinationTickets,
    DrawTrains,
    PlaceTrains
};

enum class TrainChoice : std::uint8_t
{
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
    TOP_DECK
};