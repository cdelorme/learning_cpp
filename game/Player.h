
#pragma once
#include <SFML/Graphics.hpp>

class Player {
    private:
        float bottom, left, right, top;
        float jumpHeight;
        sf::RectangleShape sprite;
        sf::Vector2f velocity;

        /**
         * Still Missing:
         *  - an actual sprite and texture instead of just a rectangle shape (for testing)
         *  - health
         *  - multiple-bounding-boxes (dependent on collision detection method)
         */

    public:
        Player();

        // update player entity, logic may be moved to render depending on collision detection
        void update();

        void setVelocity(float x, float y);
        void setVelocity(sf::Vector2f velocity);
        void changeVelocity(float x, float y);
        sf::Vector2f getVelocity();
        void setJumpHeight(float jumpHeight);
        float getJumpHeight();

        // nice abstractions for sprite, but maybe not good?
        void setPosition(float x, float y);
        void setPosition(sf::Vector2f position);
        sf::Vector2f getPosition();
        sf::Vector2f getSize();

        // these are subject to change and/or removal when rectangle becomes a sprite
        sf::RectangleShape getSprite();
        sf::RectangleShape render();
        Player(sf::Vector2f position, sf::Vector2f size, sf::Color color);

};
