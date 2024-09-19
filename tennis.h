#ifndef TENNIS_H
#define TENNIS_H

class Game
{
    int player_score;
    int opponent_score;
    bool player_serve;

public:

    Game(bool player_is_serving);

    int play_point() const;

    virtual void update_score();

    virtual int verify_winner() const;
};


class Tiebreaker : public Game
{
public:

    Tiebreaker(bool player_is_serving);

    void update_score();

    int verify_winner() const;
};


struct Set
{
    int player_games;
    int opponent_games;
    bool player_serve;

    Set(bool player_is_serving);

    int play_game() const;

    void update_games();

    int verify_winner() const;
};


#endif
