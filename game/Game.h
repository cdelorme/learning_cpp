
#pragma once

// external includes
#include <string>
#include <SFML/Graphics.hpp>

class Game {
    private:

        /**
         * physics properties
         *
         * temporarily property of the Game class
         */
        const float gravity = 1.0f;
        float movementSpeed;
        float jumpSpeed;
        float groundHeight;

        // eventually the window will be part of a display abstraction
        sf::RenderWindow window;

        sf::Clock clock;


    public:
        Game();
        void start(std::string title);
};
