#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <stdlib.h>
#include "Player.h"
using namespace std;
class Team{
    public:
    string team_loc;
    string team_nick;
    int ann;
    // Player Rooster[12];
    Team(string team_loc,string team_nick);
    Team();
    unsigned int capacity;
    unsigned int num;
    Player *Roster;
    void resize();
    bool num_check(unsigned int x);
    unsigned int put_num(Player l);
    void resize(Player *&teams, unsigned int &capacity);
};


#endif