
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    // we can set a window style as well
    // for no title bar we can use sf::Style::None
    // we can remove buttons from the titlebar with:  sf::Style::Titlebar
    // We can mix them too with sf::Style::Titlebar | sf::Style::Close
    sf::RenderWindow w(sf::VideoMode(600, 600), L"ありがとう", sf::Style::Titlebar | sf::Style::Close);

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

