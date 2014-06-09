
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2i screenDimensions(800, 600);
    sf::RenderWindow w(sf::VideoMode(screenDimensions.x, screenDimensions.y), L"Whee");
    w.setKeyRepeatEnabled(false);

    enum Direction { Down, Left, Right, Up };
    sf::Vector2i source(1, Down);
    float frameCounter = 1, switchFrame = 100, frameSpeed = 500, movementSpeed = 200;
    sf::Clock c;
    bool updateFrame = true;
    bool animateSprite = true;

    sf::Texture pT;
    sf::Sprite pS;
    pT.loadFromFile("data/sprites/image.png");
    pS.setTexture(pT);

    sf::Texture bgT;
    bgT.loadFromFile("data/levels/bg.jpg");
    sf::Sprite bg;
    bg.setTexture(bgT);
    bg.setScale(1.0f, (float)screenDimensions.y / bgT.getSize().y);
    sf::View v;
    v.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));
    v.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

    // screen scrolling method 2 (the first was using left/right keys, but then it always scrolls)
    sf::Vector2f p(0, 0);

    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            }
        }

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
            //bg.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            source.y = Right;
            pS.move(movementSpeed * c.getElapsedTime().asSeconds(), 0);
            animateSprite= true;
            //bg.move(-movementSpeed * c.getElapsedTime().asSeconds(), 0);
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

        // custom view handling

        // get center-screen relative position of character aka "Camera Position"
        p.x = pS.getPosition().x + 16 - (screenDimensions.x / 2);
        p.y = pS.getPosition().y + 16 - (screenDimensions.y / 2);

        if (p.x < 0) {
            p.x = 0;
        }
        if (p.y < 0) {
            p.y = 0;
        }

        // now the viewport only begins scrolling when the user passes the halfway mark on the screen
        v.reset(sf::FloatRect(p.x, p.y, screenDimensions.x, screenDimensions.y));

        // with the viewport we no longer need to use the bg dimensions or related calculations, we simply use the viewport
        // ideally we should have calculations for out-of-bounds, and perhaps a box in the center instead of a halfway point
        // but that's logic for another example

        w.setView(v);

        w.draw(bg);

        pS.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        w.draw(pS);

        w.display();
        w.clear();
        animateSprite = false;
    }

    return 0;
}

