#include <iostream>
#include "tennis.h"
using namespace std;

Tiebreaker::Tiebreaker(bool player_is_serving)
    : Game(player_is_serving)
{}

void Tiebreaker::update_score(bool won_point) {
    ++(won_point ? player_score : opponent_score);
    if ((player_score + opponent_score) % 2 == 1)
        player_serve = !player_serve;
}

int Tiebreaker::verify_winner() const {
    if (player_score >= 7 && (player_score - opponent_score >= 2))
        return 1;
    else if (opponent_score >= 7 && (opponent_score - player_score >= 2))
        return 2;
    else
        return 0;
}
