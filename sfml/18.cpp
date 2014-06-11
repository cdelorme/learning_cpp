
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    // let's create a control scheme
    enum Direction { Down, Left, Right, Up };

    // now we create a source that let's us know where to begin drawing from x/y coord
    sf::Vector2i source(1, Down);
    // in a later iteration we can turn the first value into a cycle 1, 2, 3 for animated sprites

    sf::Texture pT;
    sf::Sprite pS;

    //pT.loadFromFile("data/sprites/image.png", sf::IntRect(32, 0, 32, 32)); // yes we should have this in an if statement, but meh
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

        // now let's crop our image to render
        // we can do this from the sprite instead of modifying what gets loaded into the sprite (hence effient!)
        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

        w.clear();
        w.draw(pS);
        w.display();
    }

    return 0;
}

