//
// Created by danilo.bezerra on 15/12/2023.
//

#include "HumanPlayer.h"

#include <limits>
#include <algorithm>

HumanPlayer::HumanPlayer(std::string inName, std::istream &inInput) : Player(std::move(inName)), input(inInput) {

}

std::unique_ptr<Card> HumanPlayer::performAction(const GameState &state) {
    std::cout << "Your current hand: ";
    printHand();

    unoYell = false;
    int index = prompt<int>("Input the index of the card you wish to play or -1 to draw a card: ");

    std::cout << "\n";

    if (index >= 0 && index < hand.size()) {
        Card playedCard = hand[index];

        // TODO: Validate card

        hand.erase(hand.begin() + index);

        if (hand.size() == 1 && !unoYell) {
            auto response = prompt<std::string>("There's only one card!! ");
            std::transform(response.begin(), response.end(), response.begin(), ::tolower);

            if (response == "uno") {
                std::cout << "\n[" << name << "] had yelled “UNO!”\n";
                unoYell = true;
            }
        }

        return std::make_unique<Card>(playedCard);
    }

    return nullptr;
}

template<typename T> T HumanPlayer::prompt(const std::string& message) {
    T response;

    while (true) {
        std::cout << message;

        if (input >> response) {
            return response;
        }

        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Since this is the upper limit on the size of a stream, you are effectively telling cin that there is no limit to the number of characters to ignore.

        std::cout << "Invalid input! Please try again.\n";
    }
}