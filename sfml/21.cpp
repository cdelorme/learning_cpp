
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);

    // now we want to use frames to handle speed
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500;
    sf::Clock c;

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

        // the same kind of math can be applied to the inputs such that we limit movement by time and not be cpu speed

        // the logic is sound but the calculation can't be because it's very choppy, but at least it's within a feasible speed range
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

        // now we can increment our counter to check it against our speed
        frameCounter += frameSpeed * c.restart().asSeconds();
        if (frameCounter >= switchFrame) {

            // animation cycle now happens and we reset frame counter
            frameCounter = 1;

            // now we cycle the x coordinates for animation
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

