#pragma once

#include <cstdint>
#include <iostream>

enum class PlayerId : std::uint8_t
{
    One,
    Two,
    Three,
    Four,
    None
};

std::ostream& operator<<(std::ostream& os, const PlayerId& aPlayerId);

std::ostream& operator<<(std::ostream& os, const PlayerId& aPlayerId)
{
    switch (aPlayerId)
    {
        case PlayerId::One:
            os << "Player One";
            break;
        case PlayerId::Two:
            os << "Player One";
            break;
        case PlayerId::Three:
            os << "Player One";
            break;
        case PlayerId::Four:
            os << "Player One";
            break;
        case PlayerId::None:
            os << "Player One";
            break;
    }

    return os;
}