
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    // use to map to sprite facing by index (eg. first sprite is down, second is left, third is right, fourth is up)
    enum Direction { Down, Left, Right, Up };

    // create a game clock
    sf::Clock c;

    // create a sound buffer & sound object
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    // mp3 format is not supported and must be converted
    // ogg is preferred for music due to support and compression

    soundBuffer.loadFromFile("../data/sounds/1.aiff");
    sound.setBuffer(soundBuffer);

    // now let's open from file a music!
    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("../data/music/2.ogg");
    backgroundMusic.play();

    // define movement speeds
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500, movementSpeed = 200;

    // some booleans for the game
    bool paused = false;

    // both players will use the same texture
    sf::Texture playerOneTexture;
    playerOneTexture.loadFromFile("../data/sprites/player1.png");
    sf::Texture playerTwoTexture;
    playerTwoTexture.loadFromFile("../data/sprites/player2.png");

    // create two player sprites
    sf::Sprite playerOne;
    sf::Sprite playerTwo;

    // create animation and position storage for each player
    bool animateOne = true, animateTwo = true;

    // set default directions for each players facing
    sf::Vector2i playerOneDirection(1, Down);
    sf::Vector2i playerTwoDirection(1, Down);

    // set texture on each sprite
    playerOne.setTexture(playerOneTexture);
    playerTwo.setTexture(playerTwoTexture);

    // set initial player sprites
    playerOne.setTextureRect(sf::IntRect(playerOneDirection.x * 32, playerOneDirection.y * 32, 32, 32));
    playerTwo.setTextureRect(sf::IntRect(playerTwoDirection.x * 32, playerTwoDirection.y * 32, 32, 32));

    // create background image
    sf::Texture background;
    background.loadFromFile("../data/levels/1.jpg");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setScale(1.0f, (float) screenDimensions.y / background.getSize().y);

    // now we create two views, one for each viewport (playerOne and playerTwo)
    sf::View playerOneView;
    sf::View playerTwoView;

    // define each viewport
    playerOneView.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    playerOneView.setViewport(sf::FloatRect(0, 0, 0.5f, 1.0f));
    playerOneView.setSize(screenDimensions.x / 2, screenDimensions.y);
    playerTwoView.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    playerTwoView.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1.0f));
    playerTwoView.setSize(screenDimensions.x / 2, screenDimensions.y);

    // create a divider?
    sf::Vector2f viewPositionOne(screenDimensions.x / 2, screenDimensions.y / 2);
    sf::Vector2f viewPositionTwo(viewPositionOne);

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

        // use same timelapse for multiple characters calculations
        float timeLapse = c.restart().asSeconds();
        frameCounter = (animateOne || animateTwo) ? frameCounter + frameSpeed * timeLapse : 1;
        if (frameCounter >= switchFrame) {

            // reset frameCounter
            frameCounter = 1;

            // handle playerOne animation changes
            if (animateOne) {
                playerOneDirection.x++;
                if (playerOneDirection.x * 32 >= playerOneTexture.getSize().x) {
                    playerOneDirection.x = 0;
                }
                animateOne = false;
            }

            // handle playerTwo animation changes
            if (animateTwo) {
                playerTwoDirection.x++;
                if (playerTwoDirection.x * 32 >= playerTwoTexture.getSize().x) {
                    playerTwoDirection.x = 0;
                }
                animateTwo = false;
            }

        }

        // zoom by floating point, and it is ratio based on the current view size
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            playerOneView.zoom(1.01f);
            playerTwoView.zoom(1.01f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            playerOneView.zoom(0.99f);
            playerTwoView.zoom(0.99f);
        }
        // rotation effects
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            playerOneView.rotate(0.1f);
            playerTwoView.rotate(0.1f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            playerOneView.rotate(-0.1f);
            playerTwoView.rotate(-0.1f);
        }

        // play sound with "p"
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            sound.play();

            // we can also pause or stop
            // sound.stop()
            // sound.pause()
            // we can also change the pitch
            // sound.setPitch(0.5f);// float difference
            // finally, we can adjust the volume
            // sound.setVolume(50);//0-100
            //
            //
            // it also appears we can do many more things like
            // setLoop(true);//boolean
        }

        // notable concerns, it plays rediculously fast
        // to prevent this we need an audio abstraction
        // to use the game clock to stop it from happening so damn fast


        // getting it back to perfect centering is really difficult
        // ideally you should track the original or "normal" view
        // state and have a key to reset the view


        // handle viewport movement/scrolling
        if (playerOne.getPosition().x + 16 >= playerOneView.getSize().x / 2) {
            viewPositionOne.x = playerOne.getPosition().x + 16;
        } else {
            viewPositionOne.x = playerOneView.getSize().x / 2;
        }
        if (playerTwo.getPosition().x + 16 >= playerTwoView.getSize().x / 2) {
            viewPositionTwo.x = playerTwo.getPosition().x + 16;
        } else {
            viewPositionTwo.x = playerTwoView.getSize().x / 2;
        }
        playerOneView.setCenter(viewPositionOne);
        playerTwoView.setCenter(viewPositionTwo);

        // render both players (shitz bout to get crazy with double rendered views)
        playerOne.setTextureRect(sf::IntRect(playerOneDirection.x * 32, playerOneDirection.y * 32, 32, 32));
        playerTwo.setTextureRect(sf::IntRect(playerTwoDirection.x * 32, playerTwoDirection.y * 32, 32, 32));

        // render viewport one
        w.setView(playerOneView);
        w.draw(backgroundSprite);

        // draw players in viewport one
        w.draw(playerOne);
        w.draw(playerTwo);

        // render viewport two
        w.setView(playerTwoView);
        w.draw(backgroundSprite);

        // draw players in viewport two
        w.draw(playerOne);
        w.draw(playerTwo);

        // draw renders to screen and clear clutter
        w.display();
        w.clear();
    }

    return 0;
}

