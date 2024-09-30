#include <iostream>
#include "tennis.h"
using namespace std;

Match::Match(bool five_set_match)
    : sets_won(0), sets_lost(0), five_setter(five_set_match)
{}
