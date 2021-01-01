#pragma once

#include "Player.hpp"
#include "BlackCoin.hpp"
#include "RedCoin.hpp"

class Operations
{
       
    public :
        Operations();
        void strike(Player* currentPlayer,BlackCoin&);
        void multiStrike(Player* currentPlayer,BlackCoin&);
        void redStrike(Player* currentPlayer,RedCoin&);
        void strikerStrike(Player* currentPlayer);
        void defunctCoin(Player* currentPlayer,BlackCoin&);
        void NoOperation(Player* currentPlayer);
};