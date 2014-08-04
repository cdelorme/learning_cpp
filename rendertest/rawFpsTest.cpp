/**
 * Tile Map SpriteTest
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2i screenDimensions(1024, 1024);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Sprite Test");
    w.setKeyRepeatEnabled(false);

    sf::Font font;
    font.loadFromFile("../data/fonts/ForMateKonaVe.ttf");
    sf::Text fps("0", font, 32);
    fps.setColor(sf::Color::Yellow);
    int cycles = 0;
    sf::Clock c;

    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

        if (c.getElapsedTime().asSeconds() >= 1) {
            fps.setString(std::to_string(cycles));
            cycles = 0;
            c.restart();
        }

        w.draw(fps);

        w.display();
        w.clear();
        cycles++;
    }

    return 0;
}
