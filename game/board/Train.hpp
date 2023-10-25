#pragma once

#include "game/types/Color.hpp"

class Train
{
    Color theColor;

    Train() = delete;

    Train(Color aColor)
    {
        if (aColor == Color::Gray)
        {
            std::throw();
        }
        
        theColor = aColor;
    }
};