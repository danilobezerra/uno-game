//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_CARD_H
#define UNO_GAME_CARD_H

#include "Enums.h"

class Card {
    CardColor color;
    CardValue value;

public:
    Card(CardColor inColor, CardValue inValue);

    CardColor getColor() const;
    CardValue getValue() const;
};


#endif //UNO_GAME_CARD_H
