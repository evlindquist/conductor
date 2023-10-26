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

friend std::ostream& operator<<(std::ostream& os, const Color& aColor);

std::ostream& operator<<(std::ostream& os, const Color& aColor)
{
    switch (aColor)
    {
        case White:
            os << "white";
            break;
        case Pink:
            os << "Pink";
            break;
        case Red:
            os << "Red";
            break;
        case Orange:
            os << "Orange";
            break;
        case Yellow:
            os << "Yellow";
            break;
        case Green:
            os << "Green";
            break;
        case Blue:
            os << "Blue";
            break;
        case Black:
            os << "Black";
            break;
        case Rainbow:
            os << "Rainbow";
            break;
        case Gray:
            os << "Gray";
            break;
    }
}