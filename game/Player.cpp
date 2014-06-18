/**
 * Player.cpp
 *
 * author: Casey DeLorme <cdelorme@gmail.com>
 * date: 2014-6-17
 *
 * description:
 *  Player instance, describes a player entity (subject to change)
 *
 */


// external includes
#include <SFML/Graphics.hpp>

// debug includes (removed later)
#include <iostream>


// internal
#include "Player.h"


// set defaults
Player::Player() {

    // debug output
    std::cout << "player loaded" << std::endl;

    this->bottom = 0;
    this->left = 0;
    this->right = 0;
    this->top = 0;
    this->jumpHeight = 100;
    this->velocity = sf::Vector2f(0, 0);
    this->sprite.setPosition(sf::Vector2f(0, 0));
    this->sprite.setSize(sf::Vector2f(10, 10));
    this->sprite.setFillColor(sf::Color::Magenta);
};

void Player::update() {
    /**
     * Physics engine correction or pre-emption?
     * Do I assume movement and then fix it in physics?
     * Or do I supply a movement request to physics
     * and pre-emptively determine if it can be allowed?
     */

    // move character
    this->sprite.move(this->velocity.x, this->velocity.y);

    // calculate new positional data
    this->bottom = sprite.getPosition().y + sprite.getSize().y;
    this->left = sprite.getPosition().x;
    this->right = sprite.getPosition().x + sprite.getSize().x;
    this->top = sprite.getPosition().y;
}

void Player::setVelocity(float x, float y) {
    this->velocity.x = x;
    this->velocity.y = y;
}
void Player::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}
sf::Vector2f Player::getVelocity() {
    return this->velocity;
}
void Player::changeVelocity(float x, float y) {
    this->velocity.x += x;
    this->velocity.y += y;
}
void Player::setJumpHeight(float jumpHeight) {
    this->jumpHeight = jumpHeight;
}
float Player::getJumpHeight() {
    return this->jumpHeight;
}

// abstractions
sf::Vector2f Player::getPosition() {
    return this->sprite.getPosition();
}
sf::Vector2f Player::getSize() {
    return this->sprite.getSize();
}
void Player::setPosition(float x, float y) {
    this->sprite.setPosition(sf::Vector2f(x, y));
}
void Player::setPosition(sf::Vector2f position) {
    this->sprite.setPosition(position);
}


// subject to change when sprite becomes a sf::Sprite
sf::RectangleShape Player::getSprite() {
    return this->sprite;
}

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color) {

    // debug output
    std::cout << "player loaded" << std::endl;

    this->bottom = 0;
    this->left = 0;
    this->right = 0;
    this->top = 0;
    this->jumpHeight = 100;
    this->velocity = sf::Vector2f(0, 0);
    this->sprite.setPosition(position);
    this->sprite.setFillColor(color);
    this->sprite.setSize(size);
}

sf::RectangleShape Player::render() {
    // perform any extra pre-render calculations here

    return this->sprite;
}
