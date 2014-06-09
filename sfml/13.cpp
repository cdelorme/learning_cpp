
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

            // now we can try adding text to the screen?

            if (e.type == sf::Event::TextEntered) {

                // we can grab unicode text
                std::cout << e.text.unicode << std::endl;

                // you can convert it to char via
                std::cout << (char)e.text.unicode << std::endl;

                // you can use an ascii range to limit input as well
            }
            // this one is an alternative, if we wanted to use the input in another way (as an example)
            // imagine an mmo, where hotkeys are not the same as chat entry
            // you might only listen for textentered when the chat is active, otherwise you listen for keypressed for hotkeys

            // also important to note, that it does not interpret ime, such as japanese characters when that is turned on (at least on osx)

        }
        //w.display();
    }

    return 0;
}

