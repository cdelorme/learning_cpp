
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    // use to map to sprite facing by index (eg. first sprite is down, second is left, third is right, fourth is up)
    enum Direction { Down, Left, Right, Up };

    // create a game clock
    sf::Clock c;

    // still not sure that this is the best approach, going to try some alternatives soon
    // define some movement speed controls instead of using the cpu as a measurement
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500, movementSpeed = 200;

    // some booleans for the game
    bool paused = false;

    // both players will use the same texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../data/sprites/player1.png");

    // create two player sprites
    sf::Sprite playerOne;
    sf::Sprite playerTwo;

    // create animation and position storage for each player
    bool animateOne = true, animateTwo = true;

    // set default directions for each players facing
    sf::Vector2i playerOneDirection(1, Down);
    sf::Vector2i playerTwoDirection(1, Down);

    // set texture on each sprite
    playerOne.setTexture(playerTexture);
    playerTwo.setTexture(playerTexture);

    // set initial player sprites
    playerOne.setTextureRect(sf::IntRect(playerOneDirection.x * 32, playerOneDirection.y * 32, 32, 32));
    playerTwo.setTextureRect(sf::IntRect(playerTwoDirection.x * 32, playerTwoDirection.y * 32, 32, 32));

    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

        // player one controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            playerOneDirection.y = Up;
            playerOne.move(0, -movementSpeed * c.getElapsedTime().asSeconds());
            animateOne = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            playerOneDirection.y = Down;
            playerOne.move(0, movementSpeed * c.getElapsedTime().asSeconds());
            animateOne = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerOneDirection.y = Left;
            playerOne.move(-movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateOne = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            playerOneDirection.y = Right;
            playerOne.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateOne = true;
        }

        // player two controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            playerTwoDirection.y = Up;
            playerTwo.move(0, -movementSpeed * c.getElapsedTime().asSeconds());
            animateTwo = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            playerTwoDirection.y = Down;
            playerTwo.move(0, movementSpeed * c.getElapsedTime().asSeconds());
            animateTwo = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            playerTwoDirection.y = Left;
            playerTwo.move(-movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateTwo = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            playerTwoDirection.y = Right;
            playerTwo.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateTwo = true;
        }

        // this may be bad practice using a single frameCounter with logic for either player
        // however in this scenario it's the most efficient test case until we get to using
        // multiple viewports wherein the animation will be vapidly different

        // figured out a bug, this allows the restart to greatly exceed the size of our switchFrame
        // not entirely sure which logic to adjust, restart it always, or maybe we need to modulus it by switchFrame?
        // I'll test restarting always first
        float timeLapse = c.restart().asSeconds();
        frameCounter = (animateOne || animateTwo) ? frameCounter + frameSpeed * timeLapse : 1;
        if (frameCounter >= switchFrame) {

            // reset frameCounter
            frameCounter = 1;

            // handle playerOne animation changes
            if (animateOne) {
                playerOneDirection.x++;
                if (playerOneDirection.x * 32 >= playerTexture.getSize().x) {
                    playerOneDirection.x = 0;
                }
                animateOne = false;
            }

            // handle playerTwo animation changes
            if (animateTwo) {
                playerTwoDirection.x++;
                if (playerTwoDirection.x * 32 >= playerTexture.getSize().x) {
                    playerTwoDirection.x = 0;
                }
                animateTwo = false;
            }

        }

        // render both players
        playerOne.setTextureRect(sf::IntRect(playerOneDirection.x * 32, playerOneDirection.y * 32, 32, 32));
        playerTwo.setTextureRect(sf::IntRect(playerTwoDirection.x * 32, playerTwoDirection.y * 32, 32, 32));

        // for now we can simply draw both players
        w.draw(playerOne);
        w.draw(playerTwo);
        // with multiple viewports we may need to draw both players per viewport

        // draw renders to screen and clear clutter
        w.display();
        w.clear();
    }

    return 0;
}

