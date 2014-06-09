
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(600, 600), L"ありがとう");

    ////
    // we can change the size of the window at runtime
    ////

    // create a vector size
    sf::Vector2u s(400, 400);

    // we can get x and y coordinates, it's effectively the same as a pair, except first/second replaced
    std::cout << s.x << ", " << s.y << std::endl;

    // set size by vector
    w.setSize(s);



    while(w.isOpen()) {
        sf::Event e;
        while(w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }
    }

    return 0;
}

