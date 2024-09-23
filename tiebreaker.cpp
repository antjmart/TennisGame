#include <iostream>
#include "tennis.h"
using namespace std;

Tiebreaker::Tiebreaker(bool player_is_serving)
    : Game(player_is_serving)
{}

void Tiebreaker::update_score(bool won_point) {
    return;
}

int Tiebreaker::verify_winner() const {
    return 0;
}
