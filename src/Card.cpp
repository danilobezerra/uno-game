//
// Created by danilo.bezerra on 13/12/2023.
//

#include "Card.h"

#include "GameState.h"

Card::Card(CardColor inColor, CardValue inValue) : color(inColor), value(inValue) {

}

CardColor Card::getColor() const {
    return color;
}

CardValue Card::getValue() const {
    return value;
}

bool Card::isValid(const GameState& state) const {
    return color == state.getTopDiscardCard()->getColor() || value == state.getTopDiscardCard()->getValue();
}

void Card::setValueToStream(std::ostream &stream) const {
    switch (value) {
        case CardValue::ZERO:
        case CardValue::ONE:
        case CardValue::TWO:
        case CardValue::THREE:
        case CardValue::FOUR:
        case CardValue::FIVE:
        case CardValue::SIX:
        case CardValue::SEVEN:
        case CardValue::EIGHT:
        case CardValue::NINE:
            stream << static_cast<int>(value); break;
        case CardValue::PLUS_TWO:
            stream << "+2"; break;
        case CardValue::REVERSE:
            stream << "REV"; break;
        case CardValue::JUMP:
            stream << "JMP"; break;
        case CardValue::PLUS_FOUR:
            stream << "W+4"; break;
        case CardValue::PLUS_TWO_DISCARD:
            stream << "+2D"; break;
        case CardValue::SWITCH_HAND:
            stream << "SWH"; break;
    }
}

void Card::setColorToStream(std::ostream& stream) const {
    switch (color) {
        case CardColor::BLUE:
            stream << "\033[34mB"; break;
        case CardColor::YELLOW:
            stream << "\033[33mY"; break;
        case CardColor::RED:
            stream << "\033[31mR"; break;
        case CardColor::GREEN:
            stream << "\033[32mG"; break;
    }
}

std::ostream& operator<<(std::ostream& stream, const Card& card) {
    card.setColorToStream(stream);
    card.setValueToStream(stream);

    stream << "\033[0m";
    return stream;
}