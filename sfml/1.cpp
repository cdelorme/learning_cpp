
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    // special character support (effectively wide-strings are required for windows)
    // however japanese characters especially, and btw this appears to be a utf-16 string
    // which is apparently more memory efficient at handling asian characters
    // taking 2x instead of 3x bits
    // std::wstring title = L"ありがとう";
    // sf::RenderWindow window(sf::VideoMode(600, 600), title);

    //sf::RenderWindow window(sf::VideoMode(600, 600), "My First Sfml Game");
    sf::RenderWindow window(sf::VideoMode(600, 600), L"ありがとう");

    // alternative to creating the window outside of the constructor:
    //Window.create(sf::VideoMode(600, 600), "My First Sfml Game");

    // gui loop to keep the software running while the window is open
    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            // this loop happens when events occur

            // closed window detection
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}

