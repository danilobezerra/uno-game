//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_DECK_H
#define UNO_GAME_DECK_H

#include <algorithm>
#include <vector>
#include "Card.h"
#include "Enums.h"

class Deck {
    std::vector<Card> cards;

    static size_t randomIndex(size_t n);

public:
    Deck(bool oldRules);

    void shuffle();
    Card draw();
    size_t count();
};


#endif //UNO_GAME_DECK_H
