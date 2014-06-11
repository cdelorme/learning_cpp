
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {
    sf::Vector2i screenDimensions(800, 600);
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

    // let's draw text
    // for this to work we need a font file
    sf::Font fnt;
    fnt.loadFromFile("../data/fonts/ForMateKonaVe.ttf");// we can wrap this in an if/then to test that it loads
    sf::String words = " ";
    sf::Text sT(words, fnt, 40);

    // we can style our text as well
    sT.setColor(sf::Color(44, 27, 180, 197));
    sT.setStyle(sf::Text::Bold | sf::Text::Italic);

    // in my several tests, I've found the text handling to be INCREDIBLY buggy
    // if the string is not set (eg. null) OR is empty (eg. "") we get an malloc error
    // for whatever reason when the application ends it is trying to free a pointer to null or empty string
    // my solution (besides a submitting a patch) is to create a string with a space character as a placeholder

    // to handle word-wrapping we would need to create a vector of strings
    // and use the size via getGlobalBounds against the window size to handle the width
    // it gets much more complex with translations, but meh

    while (w.isOpen()) {

        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed || e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
                w.close();
            } else if (e.type == sf::Event::TextEntered) {
                if (e.text.unicode >= 32 && e.text.unicode <= 126) {

                    // add character
                    words += (char) e.text.unicode;

                } else if (e.text.unicode == 8) {

                    // backspace
                    words.erase(words.getSize() - 1, words.getSize());

                }

                sT.setString(words);
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

        // now we draw the text
        w.draw(sT);

        w.display();
        w.clear();
        animateSprite = false;
    }

    return 0;
}

