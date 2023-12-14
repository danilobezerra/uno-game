#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "GameMatch.h"

int main() {
    srand(time(NULL));

    Deck deck;

    std::vector<Player> players;
    players.emplace_back(Player());
    players.emplace_back(Player());
    players.emplace_back(Player());

    GameMatch match = GameMatch(deck, players);
    int numberOfMatches = 0;

    do {
        std::cout << "Starting Match #" << numberOfMatches + 1 << std::endl;
        match.play();

        numberOfMatches++;
    } while (!match.isGameOver());

    return 0;
}
