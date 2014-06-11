
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);
    float frameCounter = 1, switchFrame = 30, frameSpeed = 200;
    sf::Clock c;
    bool updateFrame = true;
    bool animateSprite = true;

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("../data/sprites/player1.png");
    pS.setTexture(pT);

    // we can check joystick connectivity at boot time, so we can capture already connected joysticks now
    if (sf::Joystick::isConnected(0)) {
        // 0 is the index in the array of joysticks fyi
        // we can get buttons for a joystick with this
        int buttons = sf::Joystick::getButtonCount(0);
    }

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }

        // here is the appropriate logic to adjust for smoother movement speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            source.y = Up;
            pS.move(0, -1 * c.getElapsedTime().asSeconds() * frameSpeed);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            source.y = Down;
            pS.move(0, 1 * c.getElapsedTime().asSeconds() * frameSpeed);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            source.y = Left;
            pS.move(-1 * c.getElapsedTime().asSeconds() * frameSpeed, 0);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(1 * c.getElapsedTime().asSeconds() * frameSpeed, 0);
            animateSprite= true;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mP = sf::Mouse::getPosition(w);
            pS.setPosition(mP.x, mP.y);
        }

        // for our main loop to continue capturing joystick events, we have to update its state via:
        sf::Joystick::update();

        // arguments to check button are index, then button id
        if (sf::Joystick::isButtonPressed(0, 1)) {
            // button1 for joystick0 is pressed!
        }

        frameCounter = (updateFrame) ? frameCounter + frameSpeed * c.restart().asSeconds() : 1;
        if (frameCounter >= switchFrame) {
            frameCounter = 1;
        }

        if (animateSprite) {
            source.x++;
            if (source.x * 32 >= pT.getSize().x) {
                source.x = 0;
            }
        }
        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);
        w.display();
        w.clear();

        // we can use this new animateSprite boolean to prevent
        // sprite animation when the user is stationary
        // or as a switch to the idle animation (if it has one)
        animateSprite = false;
    }

    return 0;
}

