//
// Created by danilo.bezerra on 12/12/2023.
//

#ifndef UNO_GAME_GAMEMATCH_H
#define UNO_GAME_GAMEMATCH_H

#include "Deck.h"
#include "Player.h"

class GameMatch {
    Deck deck;
    std::vector<Card> discardPile;
    std::vector<Player> players;

public:
    GameMatch(Deck &inDeck, std::vector<Player> &inPlayers);

    void play();

    bool isGameOver();
};


#endif //UNO_GAME_GAMEMATCH_H
