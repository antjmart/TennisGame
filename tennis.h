#include <iostream>

#ifndef TENNIS_H
#define TENNIS_H

class Game
{
    int player_score;
    int opponent_score;
    bool player_serve;

public:

    Game(bool player_is_serving);

    bool play_point() const;

    virtual void update_score(bool won_point);

    virtual int verify_winner() const;
};


class Tiebreaker : public Game
{
public:

    Tiebreaker(bool player_is_serving);

    void update_score(bool won_point);

    int verify_winner() const;
};


class Set
{
    int player_games;
    int opponent_games;

public:

    bool player_serve;

    Set(bool player_is_serving);

    int play_game() const;

    void update_games();

    int verify_winner() const;

    friend std::ostream & operator << (std::ostream out, const Set & s);
};


class Match
{
    Set sets[5];
    int sets_won;
    int sets_lost;
    int max_sets;

public:

    Match(bool three_set_match);

    Match(const Match & m);

    int play_set() const;

    void update_sets();

    int verify_match_finish() const;

    friend std::ostream & operator << (std::ostream out, const Match & m);
};


#endif
