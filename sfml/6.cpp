
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    sf::Time t;

    // we can also use clocks, which automatically start
    sf::Clock c;
    // it has two methods: c.getElapsedTime(), c.restart()

    while (w.isOpen()) {
        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }

            // we can use the clock to see how fast our main loop runs
            // however, within the pollEvent while loop we will only see it on events like mouse move (otherwise it'd be insanely fast screen garbage)

            // we can use c.getElapsedTime() OR if we plan to reset the clock per loop we can just use c.restart() which also returns the elapsed time
            // this is more efficient
            t = c.restart();

            // microseconds makes the most sense
            //std::cout << t.asSeconds() << std::endl;
            //std::cout << t.asMilliseconds() << std::endl;
            std::cout << t.asMicroseconds() << std::endl;
        }
    }

    return 0;
}

