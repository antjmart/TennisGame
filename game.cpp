#include <iostream>
#include <string>
#include "tennis.h"
using namespace std;


Game::Game(bool player_is_serving)
    : player_score(0), opponent_score(0), player_serve(player_is_serving)
{}


bool Game::play_point() const {
    if (player_serve)
        cout << "You serve, ";
    else
        cout << "You receive, ";
    
    cout << "Point Win? (y/n): ";
    string input_line;
    getline(cin, input_line);

    while (input_line != "y" && input_line != "n") {
        cout << "Input must be y or n: ";
        getline(cin, input_line);
    }
    return input_line == "y";
}


void Game::update_score(bool won_point) {
    int *winner_score = won_point ? &player_score : &opponent_score;
    int *loser_score = won_point ? &opponent_score : &player_score;

    switch (*winner_score) {
        case 30:
            *winner_score = 40;
            break;
        case 40:
            switch (*loser_score) {
                case 40:
                    *winner_score = 45;
                    break;
                case 45:
                    *loser_score = 40;
                    break;
                default:
                    *winner_score = 60;
            }

            break;
        default:
            *winner_score += 15;
    }
}


int Game::verify_winner() const {
    if (player_score >= 60)
        return 1;
    else if (opponent_score >= 60)
        return 2;
    else
        return 0;
}


ostream & operator << (ostream & out, const Game & g) {
    out << "Score: ";
    
    if (g.player_score == 45)
        out << "AD";
    else
        out << g.player_score;
    out << " - ";

    if (g.opponent_score == 45)
        out << "AD";
    else
        out << g.opponent_score;
    
    return out;
}
