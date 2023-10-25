#pragma once

#include <cstdint>

static constexpr NUM_TRAIN_COLORS = 9;

enum class Color : std::uint8_t
{
    White,
    Pink,
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Black,
    Rainbow,
    Gray
};