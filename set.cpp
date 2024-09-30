#include <iostream>
#include "tennis.h"
using namespace std;

Set::Set(bool player_is_serving)
    : player_games(0), opponent_games(0), player_serve(player_is_serving)
{}

ostream & operator << (ostream & out, const Set & s) {
    out << s.player_games << " - " << s.opponent_games;
    return out;
}

bool Set::play_game() const {
    int game_winner = 0;
    Game game(player_serve);

    while (game_winner == 0) {
        game.update_score(game.play_point());
        game_winner = game.verify_winner();
    }

    return game_winner == 1;
}

void Set::update_games(bool won_game) {
    ++(won_game ? player_games : opponent_games);
    player_serve = !player_serve;
}
