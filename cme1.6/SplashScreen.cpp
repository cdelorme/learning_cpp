#include <SFML/Graphics.hpp>
#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    // construct!
    // to avoid null pointer errors always set text to a non empty string
//    this->text.setString(" ");
}

SplashScreen::~SplashScreen() {
    // destruct!
}

void SplashScreen::loadContent() {
    // load font
//    this->font.loadFromFile("../data/fonts/ForMateKonaVe.ttf");
//    this->text.setString("Splash Screen");
//    this->text.setFont(this->font);
//    this->text.setCharacterSize(18);
}
void SplashScreen::unloadContent() {

}
void SplashScreen::update() {

}
void SplashScreen::draw(sf::RenderWindow &window) {
    window.draw(this->text);
}
