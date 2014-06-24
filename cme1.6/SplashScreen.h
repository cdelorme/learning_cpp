#pragma once
#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class SplashScreen : GameScreen {
    private:
        sf::Font font;
        sf::Text text;

    public:
        SplashScreen();
        ~SplashScreen();
        void loadContent();
        void unloadContent();
        void update();
        void draw(sf::RenderWindow &window);
};

