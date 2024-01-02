//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_CARD_H
#define UNO_GAME_CARD_H

#include "Enums.h"

#include <iostream>

class Card {
    CardColor color;
    CardValue value;

public:
    Card(CardColor inColor, CardValue inValue);

    CardColor getColor() const;
    CardValue getValue() const;
    std::string_view toString() const;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);
};


#endif //UNO_GAME_CARD_H
