#pragma once
#include <string>
#include "GameScreen.h"

#define ScreenWidth 1200
#define ScreenHeight 675

class ScreenManager {
    private:
        std::string text;
        GameScreen* currentScreen;
        GameScreen* newScreen;

    public:
        ScreenManager();
        ~ScreenManager();

        void setText(std::string text);
        void drawText();

        void loadContent();
        void update();
        void draw(sf::RenderWindow &window);

};

