//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_CARD_H
#define UNO_GAME_CARD_H

#include "Enums.h"

class GameState;

class Card {
    CardColor color;
    CardValue value;

    void setColorToStream(std::ostream& stream) const;
    void setValueToStream(std::ostream& stream) const;

public:
    Card(CardColor inColor, CardValue inValue);

    CardColor getColor() const;
    CardValue getValue() const;
    bool isValid(const GameState& state) const;

    friend std::ostream& operator<<(std::ostream& stream, const Card& card);

};


#endif //UNO_GAME_CARD_H
