//
// Created by danilo.bezerra on 15/12/2023.
//

#ifndef UNO_GAME_HUMANPLAYER_H
#define UNO_GAME_HUMANPLAYER_H

#include "Player.h"
#include "Card.h"

class HumanPlayer : public Player {
    std::istream& input;

    template<typename T> T prompt(const std::string& message);
    bool isOptionValid(int index) const;
    void handleUnoYell();

public:
    HumanPlayer(std::string inName, std::istream& inInput);
    std::unique_ptr<Card> performAction(const GameState &state) override;

};

#endif //UNO_GAME_HUMANPLAYER_H
