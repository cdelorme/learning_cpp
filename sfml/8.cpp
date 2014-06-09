
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");

    // create a string to display
    std::wstring message = L"おひよございます！";

    // create an empty display string
    std::wstring display = L"";

    // an index for later
    int index = 0;

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }

            // two types of keyboard events
            // sf::KeyPressed, sf::KeyReleased, sf::KeyEvent (???)
            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Return) {

                    // events are not designed for realtime, and have a delay
                    // therefore things like keypress holding a key down will be awkward in timing

                    // append message to display 1 character at a time?
                    if (index < message.size()) {
                        display += message[index];
                        index++;
                    }

                    // let's try this?
                    w.setTitle(display);

                    // cout and wstrings don't get along, and also
                    // japanese characters are not supported by the console and will not print
                    //std::wcout << L"ありがとう" << std::endl;

                }
            }

        }

        // let's disable this to reduce the heat my laptop makes when running things
        //w.display();
    }

    return 0;
}

