#include <iostream>
#include <vector>
#include <memory>

#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "GameMatch.h"

int main() {
    srand(time(NULL));

    bool newRules = false;
    Deck deck { newRules };

    std::vector<std::unique_ptr<Player>> players;

    HumanPlayer p1("You");
    players.emplace_back(std::unique_ptr<Player>(new HumanPlayer(p1)));

    AIPlayer p2("CPU #1");
    players.emplace_back(std::unique_ptr<Player>(new AIPlayer(p2)));

    AIPlayer p3("CPU #2");
    players.emplace_back(std::unique_ptr<Player>(new AIPlayer(p3)));

    GameMatch match = GameMatch(deck, std::move(players));
    int numberOfMatches = 0;

    do {
        std::cout << "Starting Match #" << numberOfMatches + 1 << std::endl;
        match.play();

        numberOfMatches++;
    } while (!match.isGameOver());

    return 0;
}
