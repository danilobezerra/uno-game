//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < static_cast<int>(CardColor::YELLOW) + 1; i++) {
        for (int j = 0; j < static_cast<int>(CardValue::JUMP) + 1; j++) {
            Card card = Card(static_cast<CardColor>(i), static_cast<CardValue>(j));
            cards.push_back(card);
        }
    }
}

/*
 * Is this C implementation of Fisher-Yates shuffle correct?
 * https://stackoverflow.com/a/3348142ccc
 */
size_t Deck::randomIndex(size_t n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int random;

    do {
        random = rand();
    } while (random >= limit);

    return random % n;
}

/*
 * Fisher–Yates shuffle Algorithm
 * https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
 */
void Deck::shuffle() {
    for (size_t i = cards.size() - 1; i > 0; i--) {
        size_t j = randomIndex(i + 1);
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