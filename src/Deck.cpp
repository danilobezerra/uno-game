//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Deck.h"

Deck::Deck() {

    // TODO: create Deck only with 0-9
    for (int i = 0; i < static_cast<int>(CardColor::GREEN) + 1; i++) {
        cards.emplace_back(static_cast<CardColor>(i), CardValue::ZERO);

        for (int j = 1; j < static_cast<int>(CardValue::NINE) + 1; j++) {
            Card card = Card(static_cast<CardColor>(i), static_cast<CardValue>(j));

            cards.push_back(card);
            cards.push_back(card);
        }

        //cards.emplace_back(static_cast<CardColor>(i), CardValue::PLUS_TWO);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::PLUS_TWO);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::PLUS_TWO);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::JUMP);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::JUMP);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::REVERSE);
        cards.emplace_back(static_cast<CardColor>(i), CardValue::REVERSE);

        //cards.emplace_back(static_cast<CardColor>(i), CardValue::REVERSE);
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