//
// Created by danilo.bezerra on 15/12/2023.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string inName, std::istream &inInput) : Player(std::move(inName)), input(inInput) {
    std::cout << "Player [" << getName() << "] created.\n";
}

Card HumanPlayer::performAction(const GameState &state) {
    int index;

    while (true) {
        printHand();

        std::cout << "Input the index of the card you wish to play:\n";

        if (input >> index && index >= 0 && index < hand.size()) {
            std::cout << "\n";

            Card playedCard = hand[index];
            hand.erase(hand.begin() + index);

            return playedCard;
        }

        input.clear();
        std::cout << "Invalid input! Try again with a valid integer index.\n";
    }
}
