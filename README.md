# TennisGame
This project is a text-based simulation of a tennis interactive game. In this game, you play through individual tennis matches, following all the conventional standards of tennis rules and scoring.

At the start of each match, you choose whether to play a best of 3 set match, or a best of 5 set match. Then, a match begins between you (the player), and the computer (the opponent). Points are played with the serve chosen for the correct player based on tennis rules, and after each point the score of each game is updated. Play through enough games to win or lose a set, then continue until either you or the computer opponent wins enough sets to win the match. Finally, the results of the match are printed out, and you have the choice of playing another match or not.
NOTE: Point system is a work in progress, so points are played simply by inputting the winner of the point. In the next version, points are played out with a selection of shots chosen by player input.

To play this project, the code files must be compiled with a C++ compiler into an executable. A Makefile is provided, so if both the g++ compiler and Make are installed, simply run either of these commands:

make
OR
make tennis

This will create an executable called "tengame", which will run this tennis game project. If Make is not available on your system, the g++ compiler can instead be ran directly with this command:

g++ main.cpp game.cpp tiebreaker.cpp set.cpp match.cpp -o <name of executable file>

Another C++ compiler could be used instead, but g++ is recommended.
I hope you enjoy this project, thank you.

