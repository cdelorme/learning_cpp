/**
 * Game.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-14
 *
 * description:
 *  Game instance, manages game loop & sets up its dependencies
 *
 */

//#include <ctime>
//#include <cstdlib>
//#include <vector>

// external includes
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// local includes
#include "Game.h"
#include "Player.h"

// ideally we should define defaults for physics
// we probably want to use intelligent display size checks & color-compatibility for window settings


// constructor /w defaults for physics (to be abstracted later)
Game::Game() :  movementSpeed(0.4f), jumpSpeed(1.3f), groundHeight(400) {}

// this kicks of the main game
void Game::start(std::string title) {

     // test output
    std::cout << "game loaded" << std::endl;

    /**
     * load config file data & run detection for default settings:
     *
     * - window settings (if config || use detection logic & save to config)
     * - graphics & maps
     * - music & sounds
     * - game saves (??)
     *
     */

    // window should use "smart defaults" based on the detected hardware
    // or whatever we pull from the config file
    this->window.create(sf::VideoMode(800, 640, 32), title);
    this->window.clear();

    // create player instance
    Player player(sf::Vector2f(0, 0), sf::Vector2f(20, 20), sf::Color::Red);

    while (this->window.isOpen()) {

        // clear the drawing area
        this->window.clear();

        // use event object on non-time-sensative interaction
        sf::Event event;
        while (this->window.pollEvent(event)) {

            // on exit-event or escape key end the game
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                this->window.close();
            }
        }

        /**
         * Input captured for player velocity controls
         * which needs to be abstracted into an Input
         * class somehow...
         */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.setVelocity(this->movementSpeed, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.setVelocity(-this->movementSpeed, 0);
        } else {
            player.setVelocity(0, player.getVelocity().y);
        }

        /**
         * Jump height limit is applied, but we now also need a variable
         * to set when up is not pressed AND they are currently jumping
         * otherwise we basically allow flight with a height restriction
         */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->groundHeight - player.getPosition().y < player.getJumpHeight()) {
            player.setVelocity(0, -this->jumpSpeed);
        }

        /**
         * apply gravity, noting that movement is run after, which leans towards physics and pre-emptive detection
         * also we should probably implement a max-velocity to prevent infinite speed gravity
         */
        if (player.getPosition().y + player.getSize().y < this->groundHeight || player.getVelocity().y < 0) {
            player.changeVelocity(0, this->gravity);
        } else if (player.getPosition().y > this->groundHeight || player.getVelocity().y > 0) {
            player.setPosition(player.getPosition().x, this->groundHeight - player.getSize().y);
            player.setVelocity(player.getVelocity().x, 0);
        }

        // update player movement data
        player.update();

        /**
         * draw entities & display changes
         * later we will offload this to a render/display class
         */
        // this->window.draw(background);
        this->window.draw(player.render());
        this->window.display();
    }

    // debug output
    std::cout << "game ended" << std::endl;

}
