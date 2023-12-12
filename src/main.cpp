#include "GameRound.h"

int roundsCount = 5;

int main() {
	GameRound round;

    for (int i = 0; i < roundsCount; i++) {
        round.play();
    }

	return 0;
}
