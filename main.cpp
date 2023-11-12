#include "game/Game.hpp"
// #include "game/ui/Printer.hpp"

#include <iostream>

int main()
{
    std::cout << "Hello world!" << std::endl;
    Game myGame{1};
    std::cout << "The winning player is " << myGame.play() << std::endl;

    // Printer myPrinter;
    // myPrinter.doThing();
}