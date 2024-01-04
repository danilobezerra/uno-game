//
// Created by danilo.bezerra on 15/12/2023.
//

#ifndef UNO_GAME_AIPLAYER_H
#define UNO_GAME_AIPLAYER_H

#include "Player.h"
#include "Card.h"

class AIPlayer : public Player {

public:
    using Player::Player;
    std::unique_ptr<Card> performAction(const GameState &state) override;
};

#endif //UNO_GAME_AIPLAYER_H
