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
