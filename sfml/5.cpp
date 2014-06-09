
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    // we can also math time objects
    sf::Time t = sf::seconds(2);
    sf::Time t2 = sf::milliseconds(1200);
    t -= t2;

    std::cout << t.asSeconds() << std::endl;
    std::cout << t.asMilliseconds() << std::endl;

    return 0;
}

