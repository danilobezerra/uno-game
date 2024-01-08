#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <chrono>

#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "GameMatch.h"

int playerCount = 5;

int main() {
    srand(time(NULL));

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(static_cast<unsigned>(seed));

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

    std::shuffle(players.begin(), players.end(), rng);

    GameMatch match = GameMatch(deck, std::move(players));
    int numberOfMatches = 0;

    do {
        std::cout << "Starting Match #" << numberOfMatches + 1 << std::endl;
        match.play();

        numberOfMatches++;
    } while (!match.isGameOver());

    return 0;
}
