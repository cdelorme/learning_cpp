
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

            // detecting mouse events
            if (e.type == sf::Event::MouseEntered) {
                std::cout << "Mouse Entered!" << std::endl;
            } if (e.type == sf::Event::MouseLeft) {
                std::cout << "Mouse Left..." << std::endl;
            }

            // this might be useful for example, auto-pausing if the mouse is out of bounds, because maybe we depend on the mouse exclusively for input
            // this could be jittery though, so instead using window focus might make more sense

            // we can also detect mouse moved
            if (e.type == sf::Event::MouseMoved) {
                // then we know we can get mouseMove.x and mouseMove.y coordinates
                std::cout << "Mouse Moved: " << e.mouseMove.x << ", " << e.mouseMove.y << std::endl;
                // this gives us the coordinates at the time of this event, we don't have tracking of where the mouse came from
            }

            // we can also check for mouse press
            if (e.type == sf::Event::MouseButtonPressed) {
                // obviously there are different buttons, so we can check the buttons here
                if (e.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Left at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                } else if (e.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "Right at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                } else if (e.mouseButton.button == sf::Mouse::Middle) {
                    std::cout << "Middle at " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
                }
                // there are more, but not necessary to add
                // no idea if osx has a middle on their trackpad
                // also on windows the x/y coordinates may not be accurate or match the moved coordinates?
            }

            // we can detect scrolling by mouse too
            if (e.type == sf::Event::MouseWheelMoved) {
                    std::cout << "Mouse Wheel Moved: " << e.mouseWheel.delta << ", " << e.mouseWheel.x << ", " << e.mouseWheel.y << std::endl;
                    // this only captures up and down scrolling
                    // also the delta is the speed of the scroll, positive for up, negative for down
            }

        }
        //w.display();
    }

    return 0;
}

