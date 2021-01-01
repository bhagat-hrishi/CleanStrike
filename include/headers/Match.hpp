#pragma once

#include "Board.hpp"
#include "VariadicTable.h"
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


// to print score in table format

class  Match
{
    private :
        string result;
        vector<Player>players ;
        Board board;
        int invalidInputs;
        int playersCount;
        static int activePlayer ;
        static bool comparePlayerByScore(Player player1,Player player2);
        
    public :
        Match();
        void playMatch();
        bool isMatchOver();
        void incrementInvalidInputs();
        void showPlayersScore();
        void showRemainingCoins();
        void changePlayer();
        ~Match();
};



// imp step for static variable 
// int Match::activePlayer = 0; 
