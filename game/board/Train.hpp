#pragma once

#include "game/types/Color.hpp"

#include <iostream>
#include <stdexcept>

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

    friend std::ostream& operator<<(std::ostream& os, const Train& aTrain);
};

std::ostream& operator<<(std::ostream& os, const Train& aTrain)
{
    os << aTrain.theColor << " Train";
    return os;
}

