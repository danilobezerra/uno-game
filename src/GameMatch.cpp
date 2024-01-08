//
// Created by danilo.bezerra on 12/12/2023.
//

#include "GameMatch.h"

GameMatch::GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers) : deck(inDeck), currentMatch(0), players(std::move(inPlayers)) {

}

void GameMatch::setup() {
    for (int i = 0; i < players.size(); i++) {
        playerIndexes.emplace_back(i);
        players[i]->clearHand();
    }

    deck.shuffle();

    clockwiseDirection = true;
    currentPlayerIndex = 0;

    for (auto &player : players) {
        for (int i = 0; i < 7; i++) {
            player->addToHand(deck.draw());
        }
    }

    while (deck.count() > 0) {
        drawPile.push_back(deck.draw());
    }

    discardPile.push_back(drawPile.back());
    drawPile.pop_back();
}

int GameMatch::countPoints() const {
    int totalPoints = 0;

    for (auto &player : players) {
        for (auto &card : player->openHand()) {
            switch (card.getValue()) {
                case CardValue::ZERO:
                case CardValue::ONE:
                case CardValue::TWO:
                case CardValue::THREE:
                case CardValue::FOUR:
                case CardValue::FIVE:
                case CardValue::SIX:
                case CardValue::SEVEN:
                case CardValue::EIGHT:
                case CardValue::NINE:
                    totalPoints += static_cast<int>(card.getValue());
                    break;
                case CardValue::PLUS_TWO:
                case CardValue::REVERSE:
                case CardValue::JUMP:
                    totalPoints += 20;
                    break;
                case CardValue::PLUS_FOUR:
                case CardValue::PLUS_TWO_DISCARD:
                case CardValue::SWITCH_HAND:
                    totalPoints += 50;
                    break;
            }
        }
    }

    return totalPoints;
}

void GameMatch::play() {
    setup();

    // O jogador à esquerda de quem estiver distribuindo as cartas começa o jogo, e o jogo deverá seguir em sentido horário.
    // TODO: Get random index

    int numberOfRounds = 0;

    while (!isMatchOver()) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "Round #" << numberOfRounds + 1 << ":\n";
        std::cout << "-----------------------------------------\n";

        for (size_t i = 0; i < players.size(); i++) {
            const auto& player = players[currentPlayerIndex];
            Card discardPileTop = discardPile.back();

            std::cout << discardPileTop << " is the card on top of the discard pile.\n\n";

            state.setTopDiscardCard(std::make_shared<Card>(discardPileTop));
            currentColor = discardPileTop.getColor();
            currentValue = discardPileTop.getValue();

            std::unique_ptr<Card> cardPlayed = player->performAction(state);

            if (cardPlayed) {
                std::cout << *player << " played the " << *cardPlayed << " card. " << player->getHandSize() << " cards remaining.\n";
                discardPile.push_back(*cardPlayed);

                if (player->getHandSize() == 0) {
                    std::cout << "\n=========================================\n";
                    std::cout << *player << " are the winner of the Match #" << currentMatch + 1 << "!!\n";
                    std::cout << "This match lasted for " << numberOfRounds << " rounds.\n";
                    std::cout << "=========================================\n";

                    break;
                }

                switch (cardPlayed->getValue()) {
                    case CardValue::PLUS_TWO:
                        nextPlayer();

                        players[currentPlayerIndex]->addToHand(drawPile.back());
                        drawPile.pop_back();

                        players[currentPlayerIndex]->addToHand(drawPile.back());
                        drawPile.pop_back();

                        std::cout << *players[currentPlayerIndex] << "'s round skipped and must buy 2 cards!\n";

                        break;
                    case CardValue::REVERSE:
                        clockwiseDirection ^= true;
                        std::cout << "The flow of the game were switched!\n";

                        break;
                    case CardValue::JUMP:
                        nextPlayer();
                        std::cout << *players[currentPlayerIndex] << "'s round skipped!\n";

                        break;
                    /*
                     * Extra feature
                     */
                    case CardValue::PLUS_TWO_DISCARD:
                        /*
                         * TODO: +2 discard card
                         * When used, the next player must grab 2 cards randomly from the discard deck. If there are no
                         * 2 cards available, the grab the required amount from the deck;
                         */
                        break;
                    default:
                        break;
                }
            } else {
                Card& drawnCard = drawPile.back();
                drawPile.pop_back();

                /*
                 * FIXME: Check drawn card
                 * Se o jogador não tiver uma carta que combine, deve comprar uma na pilha de Compras. Se a nova carta
                 * servir, ele pode jogá-la na mesma rodada. Caso contrário, passará a vez para o próximo jogador.
                 * O jogador não pode jogar uma carta que já estava na sua mão antes de fazer a compra.
                 */

                player->addToHand(drawnCard);
                std::cout << *player << " has no cards to play. Drawing a card... " << player->getHandSize() << " cards remaining.\n";
            }

            // TODO: Check UNO yell and punish if false

            nextPlayer();
        }

        numberOfRounds++;
    }
}

void GameMatch::nextPlayer() {
    int size = static_cast<int>(playerIndexes.size());

    if (clockwiseDirection) {
        currentPlayerIndex = (currentPlayerIndex + 1) % size;
    } else {
        currentPlayerIndex = (currentPlayerIndex - 1) % size;

        if (currentPlayerIndex < 0) {
            currentPlayerIndex = size - 1;
        }
    }
}

bool GameMatch::isMatchOver() const {
    // TODO: When there is only 1 card on the player’s hand, the player had yelled “UNO!”, and the player has used this card matching the rules, then the player is the winner and the match ends;
    bool matchOver = false;

    for (auto &player : players) {
        if (player->getHandSize() == 0) {
            matchOver = true;

            int amount = countPoints();
            player->addPoints(amount);

            break;
        }
    }

    return matchOver;
}

bool GameMatch::isGameOver() const {
    // The winner is the first to score 500 points.
    for (auto &player : players) {
        if (player->getPoints() >= 500) {
            return true;
        }
    }

    return false;
}