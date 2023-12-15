//
// Created by danilo.bezerra on 12/12/2023.
//

#include "GameMatch.h"

#include <utility>

GameMatch::GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers) : deck(inDeck), players(std::move(inPlayers)) {

}

void GameMatch::init() {
    deck.shuffle();

    for (auto &player : players) {
        player->clearHand();
    }

    // TODO: deal cards...

}

void GameMatch::play() {
    init();

    // TODO: setup game state
    GameState state;

    do {
        for (auto &player : players) {
            Card card = player->performAction(state);

            // FIXME: Debug only, remember to check it correctly
            if (card.getValue() == CardValue::REVERSE) {
                std::reverse(players.begin(), players.end());
                player->addPoints(20); // FIXME: Create a point table
            }

            if (player->getPoints() == 500) {
                // TODO: This is the winner
            }
        }
    } while (!isMatchOver());
}

bool GameMatch::isMatchOver() const {
    // TODO: When there is only 1 card on the player’s hand, the player had yelled “UNO!”, and the player has used this card matching the rules, then the player is the winner and the match ends;
    return false;
}

bool GameMatch::isGameOver() const {
    // TODO: The winner is the first to score 500 points.
    return false;
}