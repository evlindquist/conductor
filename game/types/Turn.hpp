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
    First,
    Second,
    Third,
    Fourth,
    Fifth,
    TopDeck
};