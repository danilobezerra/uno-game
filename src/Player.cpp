//
// Created by danilo.bezerra on 15/12/2023.
//

#include "Player.h"

#include <utility>

Player::Player(std::string inName) : name(std::move(inName)), points(0) {

}

Player::~Player() = default;

void Player::addToHand(Card &card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

std::string Player::getName() const {
    return name;
}

int Player::getPoints() const {
    return points;
}

void Player::addPoints(int amount) {
    points += amount;
}