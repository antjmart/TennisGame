#include <iostream>
#include <vector>

#ifndef TENNIS_H
#define TENNIS_H

class Game
{
protected:
    int player_score;
    int opponent_score;
    bool player_serve;

public:

    Game(bool player_is_serving);

    bool play_point() const;

    virtual void update_score(bool won_point);

    virtual int verify_winner() const;

    friend std::ostream & operator << (std::ostream & out, const Game & g);
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

    bool play_game() const;

    void update_games(bool won_game);

    int verify_winner() const;

    friend std::ostream & operator << (std::ostream & out, const Set & s);
};


class Match
{
    vector<Set> sets;
    int sets_won;
    int sets_lost;
    bool five_setter;

public:

    Match(bool five_set_match);

    Match(const Match & m);

    int play_set() const;

    void update_sets();

    int verify_match_finish() const;

    friend std::ostream & operator << (std::ostream & out, const Match & m);
};


#endif
