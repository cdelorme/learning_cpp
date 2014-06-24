#pragma once
#include <SFML/Graphics.hpp>

class GameScreen {
    private:

    public:
        GameScreen();
        ~GameScreen();
        virtual void loadContent();
        virtual void unloadContent();
        virtual void update();
        virtual void draw(sf::RenderWindow &window);
};

