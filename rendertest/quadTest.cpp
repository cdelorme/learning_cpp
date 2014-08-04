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

    sf::RenderStates mapState;
    mapState.texture = &tiles;

    sf::VertexArray map;
    map.setPrimitiveType(sf::Quads);
    map.resize(32 * 32 * 4);

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            sf::Vertex* quad = &map[(i + j * 32) * 4];
            quad[0].position = sf::Vector2f(i * 32, j * 32);
            quad[1].position = sf::Vector2f((i + 1) * 32, j * 32);
            quad[2].position = sf::Vector2f((i + 1) * 32, (j + 1) * 32);
            quad[3].position = sf::Vector2f(i * 32, (j + 1) * 32);
            int tile = rand() % 4;
            quad[0].texCoords = sf::Vector2f(tile * 32, 0);
            quad[1].texCoords = sf::Vector2f((tile + 1) * 32, 0);
            quad[2].texCoords = sf::Vector2f((tile + 1) * 32, 32);
            quad[3].texCoords = sf::Vector2f(tile * 32, 32);
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

        w.draw(map, mapState);

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
