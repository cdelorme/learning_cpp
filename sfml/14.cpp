
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

            // we can detect joystick events as well
            // since joysticks are somewhat erratic we can ask the user to map the input
            if (e.type == sf::Event::JoystickConnected) {
                // we get an index from an arracy of joysticks (eg. if we wanted to map multi-player via 2 controllers/joysticks
                std::cout << "Joystick " << e.joystickConnect.joystickId + 1 << " is connected." << std::endl;
            }

            // I could not test this code because I don't have a joystick
        }
        //w.display();
    }

    return 0;
}

