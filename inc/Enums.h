//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_ENUMS_H
#define UNO_GAME_ENUMS_H

#include <iostream>

enum class CardColor {
    BLUE,
    YELLOW,
    RED,
    GREEN
};

const CardColor all_card_colors[] = {
        CardColor::BLUE,
        CardColor::YELLOW,
        CardColor::RED,
        CardColor::GREEN
};

enum class CardValue {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    PLUS_TWO,
    REVERSE,
    JUMP,
    PLUS_FOUR,
    PLUS_TWO_DISCARD,
    SWITCH_HAND
};

const CardValue all_card_values[] = {
        CardValue::ZERO,
        CardValue::ONE,
        CardValue::TWO,
        CardValue::THREE,
        CardValue::FOUR,
        CardValue::FIVE,
        CardValue::SIX,
        CardValue::SEVEN,
        CardValue::EIGHT,
        CardValue::NINE,
        CardValue::PLUS_TWO,
        CardValue::REVERSE,
        CardValue::JUMP,
        CardValue::PLUS_FOUR,
        CardValue::PLUS_TWO_DISCARD,
        CardValue::SWITCH_HAND
};

#endif //UNO_GAME_ENUMS_H
