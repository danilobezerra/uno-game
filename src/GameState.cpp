//
// Created by danilo.bezerra on 15/12/2023.
//

#include "GameState.h"

std::shared_ptr<Card> GameState::getTopDiscardCard() const {
    return topDiscardCard;
}

void GameState::setTopDiscardCard(const std::shared_ptr<Card> &card) {
    topDiscardCard = card;
}