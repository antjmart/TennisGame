#include <iostream>
#include "tennis.h"
using namespace std;

Set::Set(bool player_is_serving)
    : player_games(0), opponent_games(0), player_serve(player_is_serving)
{}

