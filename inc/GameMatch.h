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
    size_t currentMatch;

    std::vector<std::unique_ptr<Player>> players;
    std::vector<Card> drawPile;
    std::vector<Card> discardPile;

    /*
     * TODO: setup game state
     */
    GameState state;

    bool clockwiseDirection;
    std::vector<int> playerIndexes;
    int currentPlayerIndex;
    CardColor currentColor;
    CardValue currentValue;

    /*
     * end game state
     */

    void setup();
    int countPoints() const;
    void nextPlayer();

public:
    GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers);

    void play();
    bool isMatchOver() const;
    bool isGameOver() const;
};


#endif //UNO_GAME_GAMEMATCH_H
