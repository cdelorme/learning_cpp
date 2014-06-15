
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Player {
    public:
        bool animate;
        sf::Vector2i size;
        sf::Vector2i facing;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        float top, left, bottom, right;

        Player() : animate(true), size(sf::Vector2i(32, 32)), facing(sf::Vector2i(1, 0)), top(0), left(0), bottom(0), right(0) {}

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
            }
            return true;
        }

};

int main() {
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    // describe movement speeds
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500, movementSpeed = 200;

    // load the music!
    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("../data/music/2.ogg");
    //backgroundMusic.play();

    // create a background
    sf::Texture background;
    background.loadFromFile("../data/levels/1.jpg");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1.0f, (float) screenDimensions.y / background.getSize().y);

    // create new player objects!
    Player playerOne, playerTwo;
    playerOne.loadSprite("../data/sprites/player1.png");
    playerTwo.loadSprite("../data/sprites/player2.png");

    // set player two's position to the opposite side of the screen at start
    playerTwo.playerSprite.move(screenDimensions.x - playerTwo.size.x, 0);

    // create a game clock
    sf::Clock c;

    while (w.isOpen()) {

        // clear the screen
        w.clear();

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

        // grab elapsed time to use for both players to avoid unfair timing
        float timeStep = c.getElapsedTime().asSeconds();

        // player one controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            playerOne.facing.y = 3;
            playerOne.playerSprite.move(0, -movementSpeed * timeStep);
            playerOne.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            playerOne.facing.y = 0;
            playerOne.playerSprite.move(0, movementSpeed * timeStep);
            playerOne.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerOne.facing.y = 1;
            playerOne.playerSprite.move(-movementSpeed * timeStep, 0);
            playerOne.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            playerOne.facing.y = 2;
            playerOne.playerSprite.move(movementSpeed * timeStep, 0);
            playerOne.animate = true;
        }

        // player two controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerTwo.facing.y = 3;
            playerTwo.playerSprite.move(0, -movementSpeed * timeStep);
            playerTwo.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerTwo.facing.y = 0;
            playerTwo.playerSprite.move(0, movementSpeed * timeStep);
            playerTwo.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerTwo.facing.y = 1;
            playerTwo.playerSprite.move(-movementSpeed * timeStep, 0);
            playerTwo.animate = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerTwo.facing.y = 2;
            playerTwo.playerSprite.move(movementSpeed * timeStep, 0);
            playerTwo.animate = true;
        }

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

