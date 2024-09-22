#include <iostream>
#include "tennis.h"

Game::Game(bool player_is_serving)
    : player_score(0), opponent_score(0), player_serve(player_is_serving)
{}

void Game::update_score() {
    return;
}

int Game::verify_winner() const {
    return 0;
}
