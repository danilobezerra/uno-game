//
// Created by danilo.bezerra on 12/12/2023.
//

#include "GameMatch.h"

GameMatch::GameMatch(Deck &inDeck, std::vector<Player> &inPlayers) : deck(inDeck), players(inPlayers) {

}

void GameMatch::play() {
    deck.shuffle();

    // TODO: deal cards...
}

bool GameMatch::isGameOver() {
    // TODO: The winner is the first to score 500 points.
    return false;
}