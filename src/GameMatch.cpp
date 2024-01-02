//
// Created by danilo.bezerra on 12/12/2023.
//

#include "GameMatch.h"

GameMatch::GameMatch(Deck &inDeck, std::vector<std::unique_ptr<Player>> inPlayers) : deck(inDeck), players(std::move(inPlayers)) {

}

void GameMatch::setup() {
    for (auto &player : players) {
        player->clearHand();
    }

    // O jogador que estiver distribuindo as cartas embaralha...
    deck.shuffle();

    // e distribui 7 cartas para cada um.
    for (auto &player : players) {
        for (int i = 0; i < 7; i++) {
            player->addToHand(deck.draw());
        }
    }

    std::cout << "O jogador que estiver distribuindo as cartas embaralha e distribui 7 cartas para cada um." << std::endl;

    // As cartas restantes devem ser colocadas viradas para baixo, formando a pilha de Compras.
    while (deck.count() > 0) {
        drawPile.push_back(deck.draw());
    }

    std::cout << "As cartas restantes devem ser colocadas viradas para baixo, formando a pilha de Compras." << std::endl;

    // A carta superior da pilha de Compras é virada para formar uma pilha de Descarte.
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
                    totalPoints += static_cast<int>(card.getValue()); // Valor Nominal
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

    std::cout << "O jogador à esquerda de quem estiver distribuindo as cartas começa o jogo, e o jogo deverá seguir em sentido horário." << std::endl;
    int numberOfRounds = 0;

    do {
        std::cout << "-----------------------------------------\n";
        std::cout << "Round #" << numberOfRounds + 1 << ":\n";
        std::cout << "-----------------------------------------\n";

        for (const auto &player : players) {
            Card topCard = discardPile.back();
            std::cout << topCard << " is the card on top of the discard pile.\n\n";

            state.setTopDiscardCard(std::make_shared<Card>(topCard));

            Card card = player->performAction(state);

            std::cout << "\n" << player->getName() << " played '" << card.toString() << "' card.\n\n";

            discardPile.push_back(card);

            // TODO: break loop if player has UNO true
        }

        numberOfRounds++;
    } while (!isMatchOver());
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