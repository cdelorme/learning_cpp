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


// ideally we should define defaults for physics
// we probably want to use intelligent display size checks & color-compatibility for window settings


// constructor /w defaults for physics (to be abstracted later)
Game::Game() :  moveSpeed(1.0f), jumpSpeed(10.0f) {}

// this kicks of the main game
void Game::start(std::string title) {

     // test output
    std::cout << "Game Loaded" << std::endl;

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

    while (this->window.isOpen()) {

        // use event object on non-time-sensative interaction
        sf::Event event;
        while (this->window.pollEvent(event)) {

            // on exit-event or escape key end the game
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                this->window.close();
            }
        }



    }

    // while (window.isOpen()) {

    //     // control velocity
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //         one.velocity.x = moveSpeed;
    //     } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //         one.velocity.x = -moveSpeed;
    //     } else {
    //         one.velocity.x = 0;
    //     }
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    //         one.velocity.y = -jumpSpeed;
    //     }

    //     // if we are floating, we want gravity
    //     if (one.rect.getPosition().y + one.rect.getSize().y < groundHeight || one.velocity.y < 0) {
    //         one.velocity.y += gravity;
    //     } else {
    //         // reset to the ground to prevent problems
    //         one.rect.setPosition(one.rect.getPosition().x, groundHeight - one.rect.getSize().y);
    //         one.velocity.y = 0;
    //     }

    //     // move based on velocity
    //     one.rect.move(one.velocity.x, one.velocity.y);

    //     // update player
    //     one.update();

    //     // let's check for collisions
    //     for (int i = 0; i < one.tiles.size(); i++) {
    //         int position = (one.tiles[i].x * mapSize.y) + one.tiles[i].y;
    //         if (position >= 0 && position < tiles.size() && tiles[position].getFillColor() == solid) {
    //             one.rect.setFillColor(sf::Color::Magenta);
    //             break;
    //         } else {
    //             one.rect.setFillColor(sf::Color::Red);
    //         }
    //     }

    //     // draw tiles with c++11 iterator
    //     for (auto i = tiles.begin(); i != tiles.end(); i++) {
    //         window.draw(*i);
    //     }

    //     // realistic falling accelerates, it does not stay static
    //     window.draw(one.rect);

    //     // draw bg
    //     window.display();
    // }

}
