//
// Created by danilo.bezerra on 13/12/2023.
//

#ifndef UNO_GAME_ENUMS_H
#define UNO_GAME_ENUMS_H

#include <iostream>

enum class CardColor {
    BLUE, // 19 Cartas Azuis (0 a 9)
    YELLOW, // 19 Cartas Amarelas (0 a 9)
    RED, // 19 Cartas Vermelhas (0 a 9)
    GREEN, // 19 Cartas Verdes (0 a 9)
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
    PLUS_TWO, // 8 Cartas 'Comprar Duas Cartas' (2 de cada cor)
    REVERSE, // 8 Cartas 'Inverter' (2 de cada cor)
    JUMP,  // 8 Cartas 'Pular' (2 de cada cor)

    /*
     * TODO: Also, you will have to build one of the 3 extra features:
     */
    PLUS_FOUR, // 4 Cartas Curinga 'Comprar Quatro Cartas'
    PLUS_TWO_DISCARD, // 4 Cartas 'Duas Cartas da Mesa' (1 de cada cor)
    SWITCH_HAND // 4 Cartas Curinga 'Trocar as Mãos'
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
