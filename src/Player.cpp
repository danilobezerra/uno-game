//
// Created by danilo.bezerra on 15/12/2023.
//

#include "Player.h"

#include <utility>

Player::Player(std::string inName) : name(std::move(inName)), points(0) {

}

Player::~Player() = default;

void Player::addToHand(const Card &card) {

    // Debug
    std::cout << "Player: " << name << std::endl;
    std::cout << card.toString() << std::endl;

    hand.push_back(card);
}

std::vector<Card> Player::openHand()  {
    return std::move(hand);
}

void Player::clearHand() {
    hand.clear();
}

size_t Player::getHandSize() const {
    return hand.size();
}

std::string_view Player::getName() const {
    return name;
}

int Player::getPoints() const {
    return points;
}

void Player::addPoints(int amount) {
    points += amount;
}