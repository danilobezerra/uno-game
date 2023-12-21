//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Card.h"

#include <sstream>

Card::Card(CardColor inColor, CardValue inValue) : color(inColor), value(inValue) {

}

CardColor Card::getColor() const {
    return color;
}

CardValue Card::getValue() const {
    return value;
}

std::string_view Card::toString() const {
    std::stringstream stream;

    switch (color) {
        case CardColor::BLUE:
            stream << "BLUE:";
            break;
        case CardColor::YELLOW:
            stream << "YELLOW:";
            break;
        case CardColor::RED:
            stream << "RED:";
            break;
        case CardColor::GREEN:
            stream << "GREEN:";
            break;
    }

    stream << static_cast<int>(value);
    return std::string_view(stream.str());
}