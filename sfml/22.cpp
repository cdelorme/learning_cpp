
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500;
    sf::Clock c;
    bool updateFrame = true;

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("data/sprites/image.png");
    pS.setTexture(pT);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            source.y = Up;
            pS.move(0, -1 / frameCounter);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            source.y = Down;
            pS.move(0, 1 / frameCounter);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            source.y = Left;
            pS.move(-1 / frameCounter, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(1 / frameCounter, 0);
        }


        // let's add mouse input
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            //updateFrame = true;
            // the above idea was dumb, lets try moving our character instead

            // to get local position we need to pass the window as an argument to the following
            sf::Vector2i mP = sf::Mouse::getPosition(w);
            pS.setPosition(mP.x, mP.y);
            // you can also use the static setPosition on Mouse to set the coordinates to a Vector2i, for local second arg is related window
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            // updateFrame = false;
        }
        // it is neigh impossible to make the above work with osx right clicks lol

//        if (updateFrame) {
//            frameCounter += frameSpeed * c.restart().asSeconds();
//        } else {
//            frameCounter = 1;
//        }
        // yay for ternary
        frameCounter = (updateFrame) ? frameCounter + frameSpeed * c.restart().asSeconds() : 1;

        if (frameCounter >= switchFrame) {
            frameCounter = 1;
            source.x++;
            if (source.x * 32 >= pT.getSize().x) {
                source.x = 0;
            }
        }
        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);
        w.display();
        w.clear();
    }

    return 0;
}

