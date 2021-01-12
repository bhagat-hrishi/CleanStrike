#pragma once

#include "Board.hpp"
#include "VariadicTable.h"
#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;


// to print score in table format

class  Match
{
    private :
        int invalidInputs;
        int playersCount;
        int activePlayer ;
        std::vector<std::string> input;
        string result;
        vector<Player>players;
        Board board;
        static bool comparePlayerByScore(Player player1,Player player2);
        void showPlayersScore();
        void showRemainingCoins();
        
    public :
        Match();
        Match(std::vector<std::string> input, std::string noOfPlayers);
        void changePlayer(int);
        void playMatch();
        bool isMatchOver();
        void incrementInvalidInputs();
        string getGameResult();
        Board getBoard();
        ~Match();
};



// imp step for static variable 
// int Match::activePlayer = 0; 
