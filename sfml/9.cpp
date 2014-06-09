
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    std::wstring message = L"おひよございます！";
    std::wstring display = L"";
    int index = 0;

    // we can prevent key repeat on a window (so holding a key down won't repeat)
    w.setKeyRepeatEnabled(false);

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }

            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Return) {
                    // now holding the enter key will not spit out the whole message
                    if (index < message.size()) {
                        display += message[index];
                        index++;
                    }
                    w.setTitle(display);
                }
            }

        }

        // let's disable this to reduce the heat my laptop makes when running things
        //w.display();
    }

    return 0;
}

