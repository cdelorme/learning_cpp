
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");

    while (w.isOpen()) {
        sf::Event e;

        // this is our main game loop where we process all automated events
        // the time and clock classes can be used to restrict framerates

        while (w.pollEvent(e)) {

            // this is our input loop where we interpret user interaction
            if (e.type == sf::Event::Closed) {
                w.close();
            }
        }

        // we can pause redraw until an event occurs with waitEvent
        if (w.waitEvent(e)) {
            // this may be useful in other ways
        }
        // in osx this also interferes with the pollEvent close detection

        // if we are drawing to the window, we need to call this per main loop
        w.display();

    }

    return 0;
}

