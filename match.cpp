#include <iostream>
#include <vector>
#include "tennis.h"
using namespace std;

Match::Match(bool five_set_match)
    : sets_won(0), sets_lost(0), five_setter(five_set_match)
{}

Match::Match(const Match & m)
    : sets(m.sets), sets_won(m.sets_won), sets_lost(m.sets_lost), five_setter(m.five_setter)
{}

ostream & operator << (ostream & out, const Match & m) {
    out << "Match Set Results:" << endl << endl;

    if (m.sets.size() == 0)
        out << "No sets played...";
    else {
        for (auto set : m.sets)
            out << set << "  ";
    }

    out << endl;
    return out;
}

int Match::play_set() {
    cout << "Starting Set " << (sets.size() + 1) << "..." << endl << endl;
    bool player_will_serve;
    if (sets.size() > 0)
        player_will_serve = sets.back().player_serve;
    else {
        player_will_serve = rand() % 2 == 0;
        cout << "Start of match, so serve will be chosen randomly..." << endl;
    }
    cout << "You will " << (player_will_serve ? "serve" : "receive") << '.' << endl << endl;

    Set set(player_will_serve);
    int set_winner = 0;
    cout << "Set Score: 0 - 0" << endl << endl;

    while (set_winner == 0) {
        set.update_games(set.play_game());
        set_winner = set.verify_winner();
        cout << "Set Score: " << set << endl << endl;
    }

    sets.push_back(set);
    return set_winner == 1;
}

void Match::update_sets(bool won_set) {
    ++(won_set ? sets_won : sets_lost);
}

int Match::verify_match_finish() const {
    int sets_needed = five_setter ? 3 : 2;

    if (sets_won >= sets_needed)
        return 1;
    else if (sets_lost >= sets_needed)
        return 2;
    else
        return 0;
}
