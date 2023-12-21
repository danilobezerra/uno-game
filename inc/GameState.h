//
// Created by danilo.bezerra on 15/12/2023.
//

#ifndef UNO_GAME_GAMESTATE_H
#define UNO_GAME_GAMESTATE_H

#include <memory>
#include <vector>
#include <map>

#include "Card.h"

class GameState {
    std::vector<std::shared_ptr<Card>> drawPile;
    std::shared_ptr<Card> topDiscardCard;

    bool clockwiseDirection;
    size_t currentPlayerIndex;

    std::vector<size_t> playerIndexOrder;
    std::map<size_t, int> playerCardCount;
    std::map<size_t, bool> playersUnoStatus;

public:
    std::shared_ptr<Card> getTopDiscardCard() const;
    void setTopDiscardCard(const std::shared_ptr<Card> &card);

    bool isClockwiseDirection() const;
    void setClockwiseDirection(bool inClockwiseDirection);

    std::vector<size_t> getPlayerIndexOrder() const;
    void setPlayerIndexOrder(std::vector<int> inPlayerIndexOrder);

    std::map<size_t, int> getPlayerCardCount() const;
    void setPlayerCardCount(std::vector<size_t> inPlayerCardCount);

    std::map<size_t, bool> getPlayersUnoStatus() const;
    void setPlayersUnoStatus(std::vector<size_t> inPlayersUnoStatus);

    void clear();
};


#endif //UNO_GAME_GAMESTATE_H
