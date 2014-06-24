#include <iostream>
#include "ScreenManager.h"
#include "SplashScreen.h"

ScreenManager::ScreenManager() {
    // construct!
//    currentScreen = SplashScreen();
}

ScreenManager::~ScreenManager() {
    // deconstruct!
}

void ScreenManager::setText(std::string text) {
    this->text = text;
}

void ScreenManager::drawText() {
    std::cout << this->text << std::endl;
}

void ScreenManager::loadContent() {
    currentScreen->loadContent();
}

void ScreenManager::update() {
    currentScreen->update();
}

void ScreenManager::draw(sf::RenderWindow &window) {
    currentScreen->draw(window);
}


