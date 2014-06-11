
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

int main() {

    // screen dimensions to help with dimensions and scaling
    sf::Vector2i screenDimensions(800, 600);
    sf::Vector2i blockDimensions(10, 10);

    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);
    float frameCounter = 1, switchFrame = 30, frameSpeed = 200;
    sf::Clock c;
    bool updateFrame = true;
    bool animateSprite = true;

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("../data/sprites/player1.png");
    pS.setTexture(pT);

    // prepare for random later
    srand(time(0));

    // vertex arrays are a special opengl solution
    // they are more efficient, but drawn statically and cannot be moved around like other sfml objects

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {

            // close on close event, or escape key
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            source.y = Up;
            pS.move(0, -1 * c.getElapsedTime().asSeconds() * frameSpeed);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            source.y = Down;
            pS.move(0, 1 * c.getElapsedTime().asSeconds() * frameSpeed);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            source.y = Left;
            pS.move(-1 * c.getElapsedTime().asSeconds() * frameSpeed, 0);
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(1 * c.getElapsedTime().asSeconds() * frameSpeed, 0);
            animateSprite= true;
        }

        // let's create a crazy randomly colored background filter by the block size we defined earlier!
        for (int i = 0; i < screenDimensions.x / blockDimensions.x; i++) {
            for (int j = 0; j < screenDimensions.y / blockDimensions.y; j++) {

                // The quads are pretty standard, but we could also use sf::Lines, or sf::LinesStrip
                //sf::VertexArray vA(sf::Quads, 4);
                sf::VertexArray vA(sf::LinesStrip, 4);

                // block position & size
                vA[0].position = sf::Vector2f(i * blockDimensions.x, j * blockDimensions.y);
                vA[1].position = sf::Vector2f(i * blockDimensions.x + blockDimensions.x, j * blockDimensions.y);
                vA[2].position = sf::Vector2f(i * blockDimensions.x + blockDimensions.x, j * blockDimensions.y + blockDimensions.y);
                vA[3].position = sf::Vector2f(i * blockDimensions.x, j * blockDimensions.y + blockDimensions.y);

                // random colors
                for (int k = 0; k < 4; k++) {
                    int red = rand() % 255;
                    int green = rand() % 255;
                    int blue = rand() % 255;
                    vA[k].color = (sf::Color(red, green, blue, 255));
                }

                // now we draw this vertex array, and it'll be like crazy static!
                w.draw(vA);
            }
        }

        // teleport character position /w centered logic
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mP = sf::Mouse::getPosition(w);
            pS.setPosition(mP.x - pS.getTextureRect().width / 2, mP.y - pS.getTextureRect().height / 2);

        }

        frameCounter = (updateFrame) ? frameCounter + frameSpeed * c.restart().asSeconds() : 1;
        if (frameCounter >= switchFrame) {
            frameCounter = 1;
        }

        if (animateSprite) {
            source.x++;
            if (source.x * 32 >= pT.getSize().x) {
                source.x = 0;
            }
        }

        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);

        w.display();
        w.clear();
        animateSprite = false;
    }

    return 0;
}

