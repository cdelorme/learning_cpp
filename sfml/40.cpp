
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * Player.cpp
 *
 * author: Casey DeLore <cdelorme@gmail.com>
 * date: 2014-6-15
 *
 * description:
 *  A player instance, tracks position, animation, sprite, etc...
 *
 */
class Player {
    public:
        bool animate;
        sf::Vector2i size;
        sf::Vector2i facing;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        float top, left, bottom, right;

        Player() : animate(true), size(sf::Vector2i(32, 32)), facing(sf::Vector2i(1, 0)), top(0), left(0), bottom(0), right(0) {}
        Player(std::string filePath, float x = 0, float y = 0) : animate(true), size(sf::Vector2i(32, 32)), facing(sf::Vector2i(1, 0)), top(0), left(0), bottom(0), right(0) {
            this->loadSprite(filePath);
            this->playerSprite.move(x, y);
        }

        void loadSprite(std::string filePath) {
            this->playerTexture.loadFromFile(filePath);
            this->playerSprite.setTexture(this->playerTexture);
        }

        void render() {
            this->playerSprite.setTextureRect(sf::IntRect(this->facing.x * this->size.x, this->facing.y * this->size.y, this->size.x, this->size.y));

            // calculate bounding box
            this->left = this->playerSprite.getPosition().x;
            this->top = this->playerSprite.getPosition().y;
            this->right = this->left + this->size.x;
            this->bottom = this->top + this->size.y;
        }

        bool collision(Player p) {
            if (this->left > p.right || this->right < p.left || this->top > p.bottom || this->bottom < p.top) {
                return false;
            } else {
                // run through additional checks using pixel-perfection!
                //
            }
            return true;
        }

};


/**
 * Game.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-15
 *
 * description:
 *  Game instance abstracts the main loop and major components
 *
 *  Temporarily includes window /w rendering, and input logic
 *
 */
class Game {
    private:
        sf::Vector2i screenDimensions;
        sf::RenderWindow window;
        float switchFrame, frameSpeed, movementSpeed;
        sf::Music backgroundMusic;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        std::vector<Player> players;
        sf::Clock gameClock;

    public:
        Game() : screenDimensions(sf::Vector2i(800, 600)), switchFrame(100), frameSpeed(500), movementSpeed(200) {

            // describe window using defaults (override with config settings later)
            this->window.create(sf::VideoMode(this->screenDimensions.x, this->screenDimensions.y), L"Game");
            this->window.setKeyRepeatEnabled(false);

            // we don't want to show the window until the game is "started"
            this->window.setVisible(false);

            // load bg music (ideally from non-hardcoded string)
            this->backgroundMusic.openFromFile("../data/music/2.ogg");

            // load background (ideally from non-hardcoded string)
            this->backgroundTexture.loadFromFile("../data/levels/1.jpg");
            this->backgroundSprite.setTexture(this->backgroundTexture);

            // set scale of background
            // we may want to use zoom effects and moving camera, which will change this
            this->backgroundSprite.setScale(1.0f, (float) this->screenDimensions.y / this->backgroundTexture.getSize().y);

            // prepare player instances (probably quite different later on)
            players.push_back(Player("../data/sprites/player1.png"));

            // disabling this temporarily
            //players.push_back(Player("../data/sprites/player2.png", this->screenDimensions.x - 32, 0));// had to hard-code this because of how I did it
        }

        void start() {

            // display window
            this->window.setVisible(true);

            // begin playing music
            this->backgroundMusic.play();

            // reset the game clock
            this->gameClock.restart();

            // track frame counter
            float frameCounter = 1;

            // start main loop
            while (this->window.isOpen()) {

                // capture certain events with polling to handle window closure events
                sf::Event event;
                while (this->window.pollEvent()) {
                    if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                        this->window.close();
                    }
                }

                // grab timeLapsed to perform movement calculations (this is still not an ideal method)
                float timeStep = c.getElapsedTime().asSeconds();

                // player movement
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    this->players[0].facing.y = 3;
                    this->players[0].playerSprite.move(0, -movementSpeed * timeStep);
                    this->players[0].animate = true;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    this->players[0].facing.y = 0;
                    this->players[0].playerSprite.move(0, movementSpeed * timeStep);
                    this->players[0].animate = true;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    this->players[0].facing.y = 1;
                    this->players[0].playerSprite.move(-movementSpeed * timeStep, 0);
                    this->players[0].animate = true;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    this->players[0].facing.y = 2;
                    this->players[0].playerSprite.move(movementSpeed * timeStep, 0);
                    this->players[0].animate = true;
                }
                // I still have to think through input handling in an abstract way
                // this should really be a loop through "controllable elements"
                // and matching assigned inputs, which should be loaded from... somewhere?

                // ideally the clock reset should happen right before render operations
                timeStep = c.restart().asSeconds();

                // from the problems I'm seeing here each player needs its own frameCounter to accomodate timelapse
                frameCounter = this->players[0].animate ? frameCounter + frameSpeed * timeStep : 1;


                // draw all content to window
                this->window.draw(this->backgroundSprite);
                this->window.draw(this->players[0].playerSprite);
                // this needs a serious abstraction of some sort

                // render display
                this->window.render();

                // clear artifacts from screen
                this->window.clear();

            }

        }

};


/**
 * NameOfGame.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-15
 *
 * description:
 *  Fires up the game and prepares initial dependencies
 *
 */
int main() {
    // we would probably load settings from a settings file here
    // create game instance and update /w loaded settings

    while (w.isOpen()) {

        // update if animation is happening
        timeStep = c.restart().asSeconds();
        frameCounter = (playerOne.animate || playerTwo.animate) ? frameCounter + frameSpeed * timeStep : 1;

        // if counter is greater than switchFrame we can render movement changes
        if (frameCounter >= switchFrame) {

            // reset frameCounter
            frameCounter = 1;

            // animate player one
            if (playerOne.animate) {
                playerOne.facing.x++;
                if (playerOne.facing.x * playerOne.size.x >= playerOne.playerTexture.getSize().x) {
                    playerOne.facing.x = 0;
                }
                playerOne.animate = false;
            }

            // animate player one
            if (playerTwo.animate) {
                playerTwo.facing.x++;
                if (playerTwo.facing.x * playerTwo.size.x >= playerTwo.playerTexture.getSize().x) {
                    playerTwo.facing.x = 0;
                }
                playerTwo.animate = false;
            }

        }

        // render to update players stats
        playerOne.render();
        playerTwo.render();

        // bounding box collision check
        if (playerOne.collision(playerTwo)) {
            std::cout << "Worlds Collide!" << std::endl;
        }

        // draw to screen
        w.draw(backgroundSprite);
        w.draw(playerOne.playerSprite);
        w.draw(playerTwo.playerSprite);

        // display
        w.display();
    }

    return 0;
}

