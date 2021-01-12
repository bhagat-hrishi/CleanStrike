#pragma once

#include "Player.hpp"
#include "Coin.hpp"

class Operations
{
       
    public :
        Operations();
         void strike(Player* currentPlayer,Coin&);
        void multiStrike(Player* currentPlayer,Coin&);
        void redStrike(Player* currentPlayer,Coin&);
        void strikerStrike(Player* currentPlayer);
        void defunctCoin(Player* currentPlayer,Coin&);
        void NoOperation(Player* currentPlayer);
};