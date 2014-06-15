/**
 * Tile Mapping /w Collision
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

class Player {
    public:
        sf::RectangleShape rect;
        float bottom, left, right, top;
        sf::Vector2i topLeft, bottomLeft, topRight, bottomRight;
        sf::Vector2f velocity;
        std::vector<sf::Vector2i> tiles;

        Player(sf::Vector2f position, sf::Vector2f size, sf::Color color) : velocity(sf::Vector2f(0, 0)) {
            this->rect.setPosition(position);
            this->rect.setSize(size);
            this->rect.setFillColor(color);
        };

        void update() {
            this->bottom = rect.getPosition().y + rect.getSize().y;
            this->left = rect.getPosition().x;
            this->right = rect.getPosition().x + rect.getSize().x;
            this->top = rect.getPosition().y;


            // these calculations do not belong here, but for now it'll do

            // calculate corners to identify active-tiles
            this->topLeft = sf::Vector2i((int)this->left / 32, (int)this->top / 32);
            this->topRight = sf::Vector2i((int)this->right / 32, (int)this->top / 32);
            this->bottomLeft = sf::Vector2i((int)this->left / 32, (int)this->bottom / 32);
            this->bottomRight = sf::Vector2i((int)this->right / 32, (int)this->bottom / 32);

            // clear tile set
            this->tiles.clear();

            // push overlapping tiles into array
            this->tiles.push_back(topLeft);
            if (std::find(this->tiles.begin(), this->tiles.end(), this->topRight) == this->tiles.end()) this->tiles.push_back(this->topRight);
            if (std::find(this->tiles.begin(), this->tiles.end(), this->bottomLeft) == this->tiles.end()) this->tiles.push_back(this->bottomLeft);
            if (std::find(this->tiles.begin(), this->tiles.end(), this->bottomRight) == this->tiles.end()) this->tiles.push_back(this->bottomRight);
        }

};

int main() {

    // prepare for random
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(800, 640, 32), "Gravity");// sized 640 for tile fitting
    const float gravity = 1.0f;
    int groundHeight = 440;
    float moveSpeed = 1.0f;
    float jumpSpeed = 10.0f;

    Player one(sf::Vector2f(0, 0), sf::Vector2f(20, 20), sf::Color::Red);

    // solid blocks are green, blue are clear (like air)
    sf::Color solid = sf::Color::Blue;
    sf::Color air(0, 240, 255);

    sf::Vector2f tileSize(32, 32);
    sf::Vector2i mapSize(25, 20);
    std::vector<sf::RectangleShape> tiles;
    for (int i = 0; i < mapSize.x; i++) {
        for (int j = 0; j < mapSize.y; j++) {

            sf::RectangleShape tile;
            tile.setPosition(i * tileSize.x, j * tileSize.y);
            tile.setSize(sf::Vector2f(tileSize.x, tileSize.y));

            // determine if this will be a solid block
            bool isSolid = rand() % 10 == 0;

            // draw block style via color, and make ground level at j = 15
            if (isSolid || j > 15) {
                tile.setFillColor(solid);
            } else {
                tile.setFillColor(air);
            }

            // add to tiles
            tiles.push_back(tile);

            // let's echo the size of tiles and the current i/j
            //std::cout << "Position: " << i << ", " << j << " : " << tiles.size() << std::endl;

        }
    }

    tiles[33].setFillColor(sf::Color::Black);

    // ideally we should be able to draw all of the rectangles once to a single sprite
    // which could then be rendered, but I wasn't able to find any easy document explaining how
    // documentation recommends using vertex arrays from SFML library, which use quads

    // my thought was renderTexture, but it appears that renderTexture is closely tied to graphics
    // power, so low powered cards restrict the size of the map

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // control velocity
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            one.velocity.x = moveSpeed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            one.velocity.x = -moveSpeed;
        } else {
            one.velocity.x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            one.velocity.y = -jumpSpeed;
        }

        // if we are floating, we want gravity
        if (one.rect.getPosition().y + one.rect.getSize().y < groundHeight || one.velocity.y < 0) {
            one.velocity.y += gravity;
        } else {
            // reset to the ground to prevent problems
            one.rect.setPosition(one.rect.getPosition().x, groundHeight - one.rect.getSize().y);
            one.velocity.y = 0;
        }

        // move based on velocity
        one.rect.move(one.velocity.x, one.velocity.y);

        // update player
        one.update();

        // let's check for collisions
        for (int i = 0; i < one.tiles.size(); i++) {
            int position = (one.tiles[i].x * mapSize.y) + one.tiles[i].y;
            if (position >= 0 && position < tiles.size() && tiles[position].getFillColor() == solid) {
                one.rect.setFillColor(sf::Color::Magenta);
                break;
            } else {
                one.rect.setFillColor(sf::Color::Red);
            }
        }

        // draw tiles with c++11 iterator
        for (auto i = tiles.begin(); i != tiles.end(); i++) {
            window.draw(*i);
        }

        // realistic falling accelerates, it does not stay static
        window.draw(one.rect);

        // draw bg
        window.display();
    }


    return 0;
}

