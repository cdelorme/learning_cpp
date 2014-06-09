
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);
    // added movementSpeed
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500, movementSpeed = 200;
    sf::Clock c;
    bool updateFrame = true;
    bool animateSprite = true;

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("data/sprites/image.png");
    pS.setTexture(pT);

    // load a background image
    sf::Texture bgT;
    bgT.loadFromFile("data/levels/bg.jpg");

    // create a sprite for the bg
    sf::Sprite bg;
    bg.setTexture(bgT);

    // scale height to window dimensions
    bg.setScale(1.0f, (float)screenDimensions.y / bgT.getSize().y);

    // to better control the background we can use a viewport
    sf::View v;
    v.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));

    // now we set the port (the whole window vertically and horizontally
    v.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));


    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

        // further improved movement speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            source.y = Up;
            pS.move(0, -movementSpeed * c.getElapsedTime().asSeconds());
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            source.y = Down;
            pS.move(0, movementSpeed * c.getElapsedTime().asSeconds());
            animateSprite= true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            source.y = Left;
            pS.move(-movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateSprite= true;

            // move bg right
            bg.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateSprite= true;

            // move bg left
            bg.move(-movementSpeed * c.getElapsedTime().asSeconds(), 0);
        }

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

        // set the view port before drawing anything
        w.setView(v);

        // you can set it back to w.getDefaultView() after to change which viewports are affected
        // this could be useful if we wanted to create multiple different sized viewports
        // for example, we can create view ports for the menubar, or split-screen game development

        // draw the background (before the player)
        w.draw(bg);

        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);

        w.display();
        w.clear();
        animateSprite = false;
    }

    return 0;
}

