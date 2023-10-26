#pragma once

#include <cstdint>
#include <iostream>

static constexpr std::size_t NUM_TRAIN_COLORS = 9;

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

std::ostream& operator<<(std::ostream& os, const Color& aColor);

std::ostream& operator<<(std::ostream& os, const Color& aColor)
{
    switch (aColor)
    {
        case Color::White:
            os << "White";
            break;
        case Color::Pink:
            os << "Pink";
            break;
        case Color::Red:
            os << "Red";
            break;
        case Color::Orange:
            os << "Orange";
            break;
        case Color::Yellow:
            os << "Yellow";
            break;
        case Color::Green:
            os << "Green";
            break;
        case Color::Blue:
            os << "Blue";
            break;
        case Color::Black:
            os << "Black";
            break;
        case Color::Rainbow:
            os << "Rainbow";
            break;
        case Color::Gray:
            os << "Gray";
            break;
    }

    return os;
}