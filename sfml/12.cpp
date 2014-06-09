
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }

            // we also have a few other key events on the window specifically
            // GainedFocus, LostFocus, and finally Resized
            if (e.type == sf::Event::GainedFocus) {
                std::cout << "Window Gained Focus!" << std::endl;
            } else if (e.type == sf::Event::LostFocus) {
                std::cout << "Window Lost Focus!" << std::endl;
            } else if (e.type == sf::Event::Resized) {
                // this is of key importance if we need to scale the game contents to the new window size!
                std::cout << "Window Changed Size to: w" << e.size.width << " x h" << e.size.height << std::endl;
            }

            // this allows us to pause the game when focus is lost.
            // this is important because the keyboard may stop working, as an example

        }
        //w.display();
    }

    return 0;
}

