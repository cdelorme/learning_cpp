
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow w(sf::VideoMode(400, 400), L"Whee");
    w.setKeyRepeatEnabled(false);

    // sfml 2.0 has many newer features
    // we can expect most to use opengl (yay~)

    // for this we'll create a texture
    sf::Texture pT;
    sf::Sprite pS;
    if (!pT.loadFromFile("../data/sprites/player1.png")) {
        std::cout << "Failed to load player image" << std::endl;
    }

    // set the image (as a texture) into the sprite
    pS.setTexture(pT);
    // you cannot delete the texture or the sprite points at null, it does not "Copy" the texture data to the sprite

    // we can also set a position for the image via the sprite
    pS.setPosition(100, 100);

    // we can draw the image onto the window
    w.draw(pS);
    // this will become laced into the background if we do not continued to draw it per main loop

    // if we run display just once from here, it will render it, but only once
    w.display();

    while (w.isOpen()) {
        sf::Event e;

        // before we render anything we need to clear the surface (I guess?)
        w.clear();
        // (edit: wow I bet that was in his original tutorial and I missed it)
        // without clearing we end up with garbage on the screen per render

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                w.close();
            }

            // we could use events to move the image in different directions
        }

        // so that it properly displays we want to add it here per main loop
        w.draw(pS);

        // finally we can actually begin the display process
        w.display();
    }

    return 0;
}

