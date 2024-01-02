#include <iostream>
#include <vector>
#include <memory>

#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "GameMatch.h"

int playerCount = 5;

int main() {
    srand(time(NULL));

    Deck deck;
    std::vector<std::unique_ptr<Player>> players;

    if (playerCount < 2 || playerCount > 10) {
        throw std::range_error("ERROR! Invalid player count.");
    }

    HumanPlayer player("You", std::cin);
    players.emplace_back(std::unique_ptr<Player>(new HumanPlayer(player)));

    for (int i = 1; i < playerCount; i++) {
        AIPlayer opponent(std::string("CPU #") + std::to_string(i));
        players.emplace_back(std::unique_ptr<Player>(new AIPlayer(opponent)));
    }

    GameMatch match = GameMatch(deck, std::move(players));
    int numberOfMatches = 0;

    do {
        // TODO: Before each game, the players must be sorted randomly;

        std::cout << "Starting Match #" << numberOfMatches + 1 << std::endl;
        match.play();

        numberOfMatches++;
    } while (!match.isGameOver());

    return 0;
}
