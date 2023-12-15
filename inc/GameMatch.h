//
// Created by danilo.bezerra on 12/12/2023.
//

#ifndef UNO_GAME_GAMEMATCH_H
#define UNO_GAME_GAMEMATCH_H

#include <memory>

#include "Deck.h"
#include "Player.h"

class GameMatch {
    Deck deck;
    std::vector<std::unique_ptr<Player>> players;

    void init();
public:
    GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers);

    void play();
    bool isMatchOver() const;
    bool isGameOver() const;
};


#endif //UNO_GAME_GAMEMATCH_H
