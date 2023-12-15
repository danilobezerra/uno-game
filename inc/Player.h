//
// Created by danilo.bezerra on 14/12/2023.
//

#ifndef UNO_GAME_PLAYER_H
#define UNO_GAME_PLAYER_H

#include <string>
#include <vector>

#include "GameState.h"
#include "Card.h"

class Player {

protected:
    std::string name;
    std::vector<Card> hand;
    int points;

public:
    Player(const std::string &inName);
    virtual ~Player();

    std::string getName() const;
    int getPoints() const;
    void addPoints(int amount);

    virtual Card performAction(const GameState &state) = 0;
};

#endif //UNO_GAME_PLAYER_H
