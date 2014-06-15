
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Gravity");

    const float gravity = 1.0f;

    sf::Vector2f velocity(sf::Vector2f(0, 0));
    int groundHeight = 440;
    float moveSpeed = 1.0f;
    float jumpSpeed = 10.0f;

    sf::RectangleShape player(sf::Vector2f(20, 20));
    player.setPosition(0, 0);
    player.setFillColor(sf::Color::Red);



    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // control velocity
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = moveSpeed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -moveSpeed;
        } else {
            velocity.x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity.y = -jumpSpeed;
        }

        // if we are floating, we want gravity
        if (player.getPosition().y + player.getSize().y < groundHeight || velocity.y < 0) {
            velocity.y += gravity;
        } else {
            // reset to the ground to prevent problems
            player.setPosition(player.getPosition().x, groundHeight - player.getSize().y);
            velocity.y = 0;
        }

        // move based on velocity
        player.move(velocity.x, velocity.y);

        // draw static bg via clear
        window.clear(sf::Color(0, 240, 255));

        // realistic falling accelerates, it does not stay static
        window.draw(player);

        // draw bg
        window.display();
    }


    return 0;
}

