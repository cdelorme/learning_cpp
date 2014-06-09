
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    sf::Texture pT;
    sf::Sprite pS;

    // when we load in the sprite we can also specify a portion of the image to use
    pT.loadFromFile("data/sprites/image.png", sf::IntRect(32, 0, 32, 32)); // yes we should have this in an if statement, but meh
    pS.setTexture(pT);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }

        w.clear();
        w.draw(pS);

        w.display();
    }

    return 0;
}

