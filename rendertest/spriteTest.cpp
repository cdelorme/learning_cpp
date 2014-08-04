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

    srand(time(0));

    sf::Vector2i screenDimensions(1024, 1024);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Sprite Test");
    w.setKeyRepeatEnabled(false);

    sf::Texture tiles;
    tiles.loadFromFile("../data/levels/tiles.png");

    std::vector<sf::Sprite> map;

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            sf::Sprite sprite = sf::Sprite(tiles);
            sprite.setTextureRect(sf::IntRect(32 * (rand() % 4), 0, 32, 32));
            sprite.setPosition(float(i * 32), float(j * 32));
            map.push_back(sprite);
        }
    }

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

        for (auto& sprite : map) {
            w.draw(sprite);
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
