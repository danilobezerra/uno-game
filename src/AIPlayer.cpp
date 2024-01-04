//
// Created by danilo.bezerra on 15/12/2023.
//

#include "AIPlayer.h"

std::unique_ptr<Card> AIPlayer::performAction(const GameState &state) {
    printHand();

    std::shared_ptr<Card> topCard = state.getTopDiscardCard();

    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getColor() == topCard->getColor() || hand[i].getValue() == topCard->getValue()) {
            Card playedCard = hand[i];
            hand.erase(hand.begin() + i);

            return std::make_unique<Card>(playedCard);
        }
    }

    return nullptr;
}

    // FIXME: Get card from draw pile
    return hand[0];
}