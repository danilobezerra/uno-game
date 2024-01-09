//
// Created by danilo.bezerra on 15/12/2023.
//

#include "AIPlayer.h"

std::unique_ptr<Card> AIPlayer::performAction(const GameState &state) {
    std::shared_ptr<Card> topCard = state.getTopDiscardCard();
    unoYell = false;

    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getColor() == topCard->getColor() || hand[i].getValue() == topCard->getValue()) {
            Card playedCard = hand[i];
            hand.erase(hand.begin() + i);

            if (hand.size() == 1) {
                std::cout << "[" << name << "] had yelled “UNO!”\n";
                unoYell = true;
            }

            return std::make_unique<Card>(playedCard);
        }
    }

    return nullptr;
}