
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    // we have a Time system as well
    sf::Time t = sf::seconds(2);
    // this can be equal to a microsecond, millisecond, or second value (sf::seconds(), sf::milliseconds(), sf::microseconds())

    // this will not work
    //std::cout << t << std::endl;
    // we have to format it
    std::cout << t.asSeconds() << std::endl;
    std::cout << t.asMilliseconds() << std::endl;

    return 0;
}

