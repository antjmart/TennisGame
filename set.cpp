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
