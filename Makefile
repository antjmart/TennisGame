default: tennis

tennis: main.cpp tennis.h game.cpp tiebreaker.cpp set.cpp match.cpp
	g++ main.cpp game.cpp tiebreaker.cpp set.cpp match.cpp -o tengame
