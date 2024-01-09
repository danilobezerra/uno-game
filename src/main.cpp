#include <iostream>
#include <vector>
#include <memory>
#include <random>

#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "GameMatch.h"

int playerCount = 5;
int customSeed = -1;
bool newRules = false;
bool scoreCard = false;

void getProgramOption(std::string arg) {
    if (arg[0] == '-') { // is option
        size_t n = arg.find('=');

        if (n != std::string::npos) {
            if (arg.substr(1, n - 1) == "players") {
                playerCount = stoi(arg.substr(n + 1));
            }

            if (arg.substr(1, n - 1) == "seed") {
                // FIXME: maybe this needs to convert to uint ?
                customSeed = stoi(arg.substr(n + 1));
            }
        } else {
            if (arg.substr(1) == "newrules") {
                newRules = true;
            }

            if (arg.substr(1) == "scorecard") {
                scoreCard = true;
            }
        }
    }
}

/*
 * TODO: Read command-line arguments
 * https://www.gnu.org/software/libc/manual/html_node/Argument-Syntax.html
 *
 * - "-players={0}": 2-9 players, first is always the human and the rest are CPU controlled. Default = 5.
 * - "-seed={0}: Set seed for PRNG in the game. Default = Random."
 * - "-newrules": 112 cards in total, older versions of the game will have 104 cards. Default = old.
 * - "-scorecard": Complete game with scores. Default = no scores, only one match.
 */
void extractArgs(int argc, char * const *argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            getProgramOption(argv[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    extractArgs(argc, argv);

    std::random_device seed;
    std::mt19937 rng(customSeed > 0 ? customSeed : seed());

    Deck deck(rng, newRules);
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
        match.play(rng, numberOfMatches);

        numberOfMatches++;
    } while (scoreCard && !match.isGameOver());

    return 0;
}
