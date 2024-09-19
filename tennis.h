#ifndef TENNIS_H
#define TENNIS_H

class Game
{
    int player_score;
    int other_score;
    bool your_serve;

public:

    Game();

    int play_point();

    virtual void update_score();

    virtual int verify_winner();

};

class Tiebreaker : public Game
{
public:

    Tiebreaker();

    void update_score();

    int verify_winner();
};


#endif
