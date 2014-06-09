
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

            if (e.type == sf::Event::JoystickConnected) {
                std::cout << "Joystick " << e.joystickConnect.joystickId + 1 << " is connected." << std::endl;
            } else if (e.type == sf::Event::JoystickDisconnected) {
                // we can also tell when a joystick is disconnected
                // it has the same event name
                std::cout << "Joystick " << e.joystickConnect.joystickId + 1 << " is disconnected." << std::endl;
            } else if (e.type == sf::Event::JoystickButtonPressed) {
                // and this is how we can identify buttons
                std::cout << "Joystick Button: " << e.joystickButton.button << std::endl;
            } else if (e.type == sf::Event::JoystickMoved) {
                // finally we can check joystick moved, although I have no idea how to manage multiple joysticks on a single controller
                std::cout << "Moved to position " << e.joystickMove.position << std::endl;
                // we also have joystickid, and axis
            }
            // ideally, joystick mappings should save to the device by some form of unique identifier
            // this way we can allow a joystick to disconnect and reconnect on another port so we can adjust accordingly
            // testing this on my mac with an xbox controller would be amazing
        }
        //w.display();
    }

    return 0;
}

