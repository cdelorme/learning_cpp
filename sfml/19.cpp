
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("../data/sprites/player1.png");
    pS.setTexture(pT);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            } else if (e.type == sf::Event::KeyPressed) {

                // we use our source for the map change
                if (e.key.code == sf::Keyboard::Down) {
                    source.y = Down;
                } else if (e.key.code == sf::Keyboard::Up) {
                    source.y = Up;
                } else if (e.key.code == sf::Keyboard::Left) {
                    source.y = Left;
                } else if (e.key.code == sf::Keyboard::Right) {
                    source.y = Right;
                }

            }
        }

        // now we cycle the x coordinates for animation
        source.x++;
        if (source.x * 32 >= pT.getSize().x) {
            source.x = 0;
        }
        // this will be absurdly fast because it has no framerate

        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);
        w.display();
        w.clear();
    }

    return 0;
}

