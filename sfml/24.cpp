
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(800, 600), L"Whee");
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

    // we can draw custom shapes in sfml instead of using sprites
    sf::RectangleShape rect(sf::Vector2f(20, 20));

    // we can set the color her as well, using rgba color scale
    rect.setFillColor(sf::Color(200, 0, 0, 200));
    rect.setOutlineColor(sf::Color(0, 200, 0, 200));
    rect.setOutlineThickness(2);

    // we can relocate it as well
    rect.setPosition(200, 100);

    // we can also apply a texture
    rect.setTexture(&pT);
    // it will force the texture to fit inside its limited space

    // let's create a circle, the first is the radius, the second is the number of triangles for smooth borders
    sf::CircleShape circ(50, 50);
    circ.setPosition(400, 400);

    // finally, we can draw a custom shape
    sf::ConvexShape cvs(3);
    cvs.setPoint(0, sf::Vector2f(10, 10));
    cvs.setPoint(1, sf::Vector2f(15, 15));
    cvs.setPoint(2, sf::Vector2f(20, 10));
    cvs.setOutlineColor(sf::Color::Red);
    cvs.setOutlineThickness(1);

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

        // this will create a small rectangle at the top of the screen
        w.draw(rect);

        // also a circle
        w.draw(circ);

        // and a custom shape
        w.draw(cvs);

        w.display();
        w.clear();
        animateSprite = false;
    }

    return 0;
}

