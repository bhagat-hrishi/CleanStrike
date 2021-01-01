#pragma once

#include "Operations.hpp"
#include "BlackCoin.hpp"
#include "RedCoin.hpp"

class Board
{
    private :
        // coins is composition 
        BlackCoin blackCoin;
        RedCoin  redCoin;
        int successiveInvalidInput ;
        // moves composition
        Operations moveOfCurrentPlayer;
        Player*  currentPlayer ;
    public :
        Board();
        int getBlackCoinCount();
        int getRedCoinCount();
        void setCurrentPlayer(Player*);
        Player* getCurrentPlayer();
        Operations& getCurrentOperation();
        BlackCoin& getBlackCoinRef();
        RedCoin& getRedCoinRef();
};





