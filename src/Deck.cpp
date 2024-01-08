//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Deck.h"

Deck::Deck(std::mt19937& rng, bool newRules) : generator(rng) {
    for (int i = 0; i < static_cast<int>(CardColor::GREEN) + 1; i++) {
        cards.emplace_back(static_cast<CardColor>(i), CardValue::ZERO);

        if (!newRules) {
            cards.emplace_back(static_cast<CardColor>(i), CardValue::ZERO);
        }

        for (int j = 1; j < static_cast<int>(CardValue::NINE) + 1; j++) {
            cards.push_back(cards.emplace_back(static_cast<CardColor>(i), static_cast<CardValue>(j)));
            cards.push_back(cards.emplace_back(static_cast<CardColor>(i), static_cast<CardValue>(j)));
        }

        cards.emplace_back(static_cast<CardColor>(i), CardValue::PLUS_TWO);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::PLUS_TWO);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::JUMP);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::JUMP);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::REVERSE);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::REVERSE);
    }
}

/*
 * Mersenne Twister PRNG
 * https://en.wikipedia.org/wiki/Mersenne_Twister
 */
size_t Deck::randomIndex(size_t max) {
    std::uniform_int_distribution<size_t> distribution(0, max);
    return distribution(generator);
}

/*
 * Fisher–Yates shuffle Algorithm
 * https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
 */
void Deck::shuffle() {
    for (size_t i = cards.size() - 1; i > 0; i--) {
        size_t j = randomIndex(i);

        std::swap(cards[i], cards[j]);
    }
}

Card Deck::draw() {
    if (!cards.empty()) {
        Card drawnCard = cards.back();
        cards.pop_back();

        return drawnCard;
    }

    throw std::out_of_range("ERROR! Deck is empty.");
}

size_t Deck::count() {
    return cards.size();
}