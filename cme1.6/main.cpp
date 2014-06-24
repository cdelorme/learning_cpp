#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "SplashScreen.h"

// @link https://www.youtube.com/v/Q7O13p_IY0k&list=PLCB3138ADCE90F2EC&index=1&hd=1&autoplay=1
// continue following tutorial

using namespace std;

int main() {

    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "Platformer Game Window");
    ScreenManager screen = ScreenManager();

    // test create new SplashScreen & font loading
    SplashScreen splash = SplashScreen();
    splash.loadContent();

    while (window.isOpen()) {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }


        window.display();
    }

    return 0;
}

