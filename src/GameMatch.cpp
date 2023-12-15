//
// Created by danilo.bezerra on 12/12/2023.
//

#include "GameMatch.h"

#include <utility>

GameMatch::GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers) : deck(inDeck), players(std::move(inPlayers)) {

}

void GameMatch::play() {
    deck.shuffle();

    // TODO: deal cards...


}

bool GameMatch::isGameOver() const {
    // TODO: The winner is the first to score 500 points.
    return false;
}