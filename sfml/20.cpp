
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
    pT.loadFromFile("data/sprites/image.png");
    pS.setTexture(pT);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }

        // for live binding outside of event polling we use this
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            source.y = Up;
            pS.move(0, -1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            source.y = Down;
            pS.move(0, 1);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            source.y = Left;
            pS.move(-1, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(1, 0);
        }

        // this is not the most ideal way to handle movement
        // you should generally have some kind of adjustment by computer

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

