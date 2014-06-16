
// include tile.h
#include "Tile.h"

void Tile::setSize(sf::Vector2i& vector) {
    this->size = vector;
}

void Tile::setSize(int x, int y) {
    this->size.x = x;
    this->size.y = y;
}

sf::Vector2i Tile::getSize() {
    return this->size;
}

void Tile::setMapCoordinates(sf::Vector2i& vector) {
    this->mapCoordinates = vector;
}

void Tile::setMapCoordinates(int x, int y) {
    this->mapCoordinates.x = x;
    this->mapCoordinates.y = y;
}

sf::Vector2i Tile::getMapCoordinates() {
    return this->mapCoordinates;
}

void Tile::setTileTexture(sf::Texture& texture) {
    this->tileTexture = texture;
}

void Tile::loadImage(std::string& filePath) {
    this->tileTexture.loadFromFile(filePath);
}

