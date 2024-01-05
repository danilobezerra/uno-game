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
    Player(std::string inName);
    virtual ~Player();

    void addToHand(const Card &card);
    size_t getHandSize() const;
    std::vector<Card> openHand();
    void clearHand();
    void printHand() const;

    std::string_view getName() const;
    int getPoints() const;
    void addPoints(int amount);

    virtual std::unique_ptr<Card> performAction(const GameState &state) = 0;

    friend std::ostream& operator<<(std::ostream& stream, const Player& player);
};

#endif //UNO_GAME_PLAYER_H
