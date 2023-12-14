//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Card.h"

Card::Card(CardColor inColor, CardValue inValue) : color(inColor), value(inValue) {

}

CardColor Card::getColor() const {
    return color;
}

CardValue Card::getValue() const {
    return value;
}