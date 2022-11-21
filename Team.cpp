#include <iostream>
#include <string>
#include "Team.h"
using namespace std;

Team::Team(string team_loc,string team_nick){

    this->team_loc = team_loc;
    this->team_nick = team_nick;
    this->ann=0;
    this->num = 0;
    this->capacity=1;
    this->Roster= new Player [capacity];
}
Team::Team(){
    this->team_loc = "";
    this->team_nick = "";
    this->ann=0;
    this->num = 0;
    this->capacity=1;
    this->Roster= new Player [capacity];
}
void Team:: resize(){
    Player *nv = new Player[capacity+1];
    for (unsigned int i = 0;i<num;i++){
        nv[i]=Roster[i];
    }
    delete[] Roster ;
    Roster = nv;
    capacity++;
    num++;
}
bool Team:: num_check(unsigned int x){

    for (unsigned int i=0;i<capacity;i++){
        if( Roster[i].taken_num==x){
            return false;
        }
    }
    return true;
}
unsigned int Team:: put_num(Player l){

    if(num_check(l.Jersey_number)==true){
         l.taken_num=l.Jersey_number;
         return l.taken_num;
    }
    else if(num_check(l.taken_num)==true){
        return l.taken_num;
    }
    for (unsigned int i= 0; i<100;i++){
        if (num_check(i)==true){
            l.taken_num=i;
            return i;
        }
    }
    
    return 0;
}

void Team::resize(Player *&roster, unsigned int &capacity){
    Player *nv = new Player[capacity+1];
    for (unsigned int i = 0;i<capacity;i++){
        nv[i]=roster[i];
    }
    delete[] roster ;
    roster = nv;
    capacity++;
}