#pragma once

#include "game/types/Color.hpp"

#include <stdexcept>

static constexpr std::size_t NUM_TRAINS_PER_COLOR = 12;
static constexpr std::size_t NUM_RAINBOW_TRAINS = 14;

class Train
{
    Color theColor;

public:
    Train()
    {
    }
    
    Train(Color aColor)
    {
        if (aColor == Color::Gray)
        {
            throw std::runtime_error("Trains cannot have the color gray");
        }
        
        theColor = aColor;
    }

    Color color()
    {
        return theColor;
    }
};