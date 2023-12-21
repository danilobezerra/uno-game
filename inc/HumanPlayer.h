//
// Created by danilo.bezerra on 15/12/2023.
//

#ifndef UNO_GAME_HUMANPLAYER_H
#define UNO_GAME_HUMANPLAYER_H

#include "Player.h"
#include "Card.h"

class HumanPlayer : public Player {

public:
    using Player::Player;
    Card performAction(const GameState &state) override;
};

#endif //UNO_GAME_HUMANPLAYER_H
