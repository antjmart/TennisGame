#include <iostream>
#include "tennis.h"
using namespace std;


Game::Game(bool player_is_serving)
    : player_score(0), opponent_score(0), player_serve(player_is_serving)
{}

int Game::play_point() const {
    cout << "Point Win: ";
    char c;
    cin >> c;

    if (c == 'y')
        return 1;
    else
        return 2;
}

void Game::update_score() {
    return;
}

int Game::verify_winner() const {
    return 0;
}
