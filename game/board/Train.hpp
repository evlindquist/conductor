#pragma once

#include "game/types/Color.hpp"

class Train
{
    Color theColor;

public:
    Train() = delete;

    Train(Color aColor)
    {
        if (aColor == Color::Gray)
        {
            std::throw();
        }
        
        theColor = aColor;
    }

    Color color()
    {
        return theColor;
    }
};