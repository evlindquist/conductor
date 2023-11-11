#include "game/game.hpp"

#include <iostream>

int main()
{
    Game myGame{1};
    std::cout << "The winning player is " << myGame.play() << std::endl;
}