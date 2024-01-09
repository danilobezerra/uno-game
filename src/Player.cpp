//
// Created by danilo.bezerra on 15/12/2023.
//

#include "Player.h"

#include <utility>

Player::Player(std::string inName) : name(std::move(inName)), unoYell(false), points(0) {
    std::cout << "Player [" << name << "] created.\n";
}

Player::~Player() = default;

bool Player::areUnoYelled() const {
    return unoYell;
}

void Player::addToHand(const Card &card) {
    hand.push_back(card);
}

std::vector<Card> Player::openHand()  {
    return std::move(hand);
}

void Player::clearHand() {
    hand.clear();
}

void Player::printHand() const {
    for (int i = 0; i < hand.size(); i++) {
        std::cout << "(" << i << ") " << hand[i];

        if (i < hand.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "\n";
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

std::ostream& operator<<(std::ostream& stream, const Player& player) {
    stream << "["<< player.name << "]";
    return stream;
}