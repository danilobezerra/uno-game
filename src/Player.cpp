//
// Created by danilo.bezerra on 15/12/2023.
//

#include "Player.h"

Player::Player(const std::string &inName) : name(inName), points(0) {

}

Player::~Player() = default;

std::string Player::getName() const {
    return name;
}

int Player::getPoints() const {
    return points;
}

void Player::addPoints(int amount) {
    points += amount;
}