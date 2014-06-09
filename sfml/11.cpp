
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
            } else if (e.type == sf::Event::MouseEntered) {
                std::cout << "Mouse Entered!" << std::endl;
            } if (e.type == sf::Event::MouseLeft) {
                std::cout << "Mouse Left..." << std::endl;
            } else if (e.type == sf::Event::MouseMoved) {
                std::cout << "Mouse Moved: " << e.mouseMove.x << ", " << e.mouseMove.y << std::endl;
            } else if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Left at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                } else if (e.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "Right at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                } else if (e.mouseButton.button == sf::Mouse::Middle) {
                    std::cout << "Middle at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                }
            } else if (e.type == sf::Event::MouseWheelMoved) {
                    std::cout << "Mouse Wheel Moved: " << e.mouseWheel.delta << ", " << e.mouseWheel.x << ", " << e.mouseWheel.y << std::endl;
            }
        }
        //w.display();
    }

    return 0;
}

