//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_DECK_H
#define UNO_GAME_DECK_H

#include <algorithm>
#include <vector>
#include <random>
#include "Card.h"
#include "Enums.h"

class Deck {
    std::vector<Card> cards;
    std::mt19937& generator;

    size_t randomIndex(size_t n);

public:
    Deck(std::mt19937& rng, bool newRules);

    void shuffle();
    Card draw();
    size_t count();
};


#endif //UNO_GAME_DECK_H
