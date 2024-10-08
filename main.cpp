#include <iostream>
#include <unistd.h>
#include "tennis.h"
using namespace std;


bool get_answer() {
    string input_line;
    getline(cin, input_line);

    while (input_line != "Y" && input_line != "N") {
        cout << "Input must be Y or N: ";
        getline(cin, input_line);
    }

    cout << endl;
    return input_line == "Y";
}


bool choose_five_setter() {
    cout << "Would you like to play a best-of-five set match?" << endl;
    cout << "If no, it will be a best-of-three set match." << endl;
    cout << "(Y / N) : ";

    return get_answer();
}


bool choose_play_again() {
    cout << "Do you want to play another match? (Y / N) : ";
    return get_answer();
}


int main()
{
    cout << "                          TENNIS GAME" << endl << endl;
    cout << "---------------------------------------------------------------" << endl << endl;
    cout << "In this game, you will give commands for your tennis player" << endl;
    cout << "in a simulated tennis match, against an automated computer" << endl;
    cout << "opponent. Win 2 sets out of 3, or 3 out of 5, to win the tennis" << endl;
    cout << "match. Actions are submitted by text input. Each action in a" << endl;
    cout << "tennis point may have different likelihoods of winning the" << endl;
    cout << "point. Good luck!" << endl << endl;
    cout << "---------------------------------------------------------------" << endl << endl;
    
    bool play_match = true;

    while (play_match) {
        cout << "Loading up a fresh, new tennis match." << endl << endl;
        cout << "---------------------------------------------------------------" << endl << endl;

        Match tennis_match(choose_five_setter());
        int match_winner = 0;

        while (match_winner == 0) {
            tennis_match.update_sets(tennis_match.play_set());
            match_winner = tennis_match.verify_match_finish();
        }

        if (match_winner == 1)
            cout << "You Won!" << endl;
        else
            cout << "You Lost!" << endl;
        sleep(2);
        cout << tennis_match << endl;
        sleep(2);
        play_match = choose_play_again();
    }

    cout << "Quitting Tennis Game..." << endl;
}
