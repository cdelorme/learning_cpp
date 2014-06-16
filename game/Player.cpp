
// #include "Player.h"

// Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color) : velocity(sf::Vector2f(0, 0)) {
//     this->rect.setPosition(position);
//     this->rect.setSize(size);
//     this->rect.setFillColor(color);
// };

// Player::update() {
//     this->bottom = rect.getPosition().y + rect.getSize().y;
//     this->left = rect.getPosition().x;
//     this->right = rect.getPosition().x + rect.getSize().x;
//     this->top = rect.getPosition().y;


//     // these calculations do not belong here, but for now it'll do

//     // calculate corners to identify active-tiles
//     this->topLeft = sf::Vector2i((int)this->left / 32, (int)this->top / 32);
//     this->topRight = sf::Vector2i((int)this->right / 32, (int)this->top / 32);
//     this->bottomLeft = sf::Vector2i((int)this->left / 32, (int)this->bottom / 32);
//     this->bottomRight = sf::Vector2i((int)this->right / 32, (int)this->bottom / 32);

//     // clear tile set
//     this->tiles.clear();

//     // push overlapping tiles into array
//     this->tiles.push_back(topLeft);
//     if (std::find(this->tiles.begin(), this->tiles.end(), this->topRight) == this->tiles.end()) this->tiles.push_back(this->topRight);
//     if (std::find(this->tiles.begin(), this->tiles.end(), this->bottomLeft) == this->tiles.end()) this->tiles.push_back(this->bottomLeft);
//     if (std::find(this->tiles.begin(), this->tiles.end(), this->bottomRight) == this->tiles.end()) this->tiles.push_back(this->bottomRight);
// }
