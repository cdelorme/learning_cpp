
/**
 * demo.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-15
 *
 * description:
 *  Starts the game up and sets conditional defaults for use globally
 *
 */

// external
#include <iostream>
#include <string>

// local
#include "Conditional.h"
#include "Game.h"

int main() {

    // test output
    std::cout << "demo loaded" << std::endl;

    // create a game instance
    Game game;

    // start!
    game.start("Game Title");

    return 0;
}


