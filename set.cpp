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
    Game *game;

    if (player_games == 6 && opponent_games == 6)
        game = new Tiebreaker(player_serve);
    else
        game = new Game(player_serve);
    
    while (game_winner == 0) {
        cout << *game << endl;
        game->update_score(game->play_point());
        game_winner = game->verify_winner();
    }

    delete game;
    return game_winner == 1;
}

void Set::update_games(bool won_game) {
    ++(won_game ? player_games : opponent_games);
    player_serve = !player_serve;
}

int Set::verify_winner() const {
    if (player_games == 7 || (player_games == 6 && opponent_games <= 4))
        return 1;
    else if (opponent_games == 7 || (opponent_games == 6 && player_games <= 4))
        return 2;
    else
        return 0;
}
