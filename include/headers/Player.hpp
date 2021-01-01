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
        void setPlayerName();
        string getName();
        void updateScore(int);
        int getFoulCount();
        void incrementFoulCount();
        void resetFoulCount();
        void resetSuccessiveNoStrikeCount();
        void resetBothNoSuccessiveStrikeAndFoulCount();
        void incrementNoSuccessiveStrikeCount();
};
