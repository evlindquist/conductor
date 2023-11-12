#pragma once

#include <iostream>

class Printer
{
public:
    Printer()
    {
        std::cout << "Made" << std::endl;
    }
    void doThing()
    {
        std::cout << "Hello world!" << std::endl;
    }
};



