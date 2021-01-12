#pragma once

#include<iostream>
#include<string>
using namespace std;

class Player {
    private :
        int score ;
        string playerName;
        int foulCount ;
        int noSuccessiveStrikeCount;
    public :
        Player();
        int getScore();
        void setPlayerName(string name);
        string getName();
        void updateScore(int);
        int getFoulCount();
        void incrementFoulCount();
        void resetFoulCount();
        void resetSuccessiveNoStrikeCount();
        void incrementNoSuccessiveStrikeCount();
        int getNoSuccessiveStrikeCount();
};
