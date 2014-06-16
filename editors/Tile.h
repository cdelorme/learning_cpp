/**
 * Tile.h
 *
 * Author: Casey DeLorme <cdelorme@gmail.com>
 * Date: 2014-6-14
 *
 * Description:
 *  Stores map data in tile-based format
 *  used by game & editor alike
 */

// prevent duplicte inclusion
#pragma once

// includes
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class Tile {
    private:
        sf::Vector2i size;
        sf::Vector2i mapCoordinates;
        sf::Texture tileTexture;
        sf::Sprite tileSprite;

    public:
        Tile() : mapCoordinates(sf::Vector2i(0, 0)) {};

        void setSize(sf::Vector2i& vector);
        void setSize(int x, int y);
        sf::Vector2i getSize();
        void setMapCoordinates(sf::Vector2i& vector);
        void setMapCoordinates(int x, int y);
        sf::Vector2i getMapCoordinates();
        void setTileTexture(sf::Texture& texture);
        void loadImage(std::string& filePath);

};

