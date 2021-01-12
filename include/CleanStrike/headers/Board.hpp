#pragma once

#include "Operations.hpp"
#include "Coin.hpp"

class Board
{
    private :
        Coin coin;
        int successiveInvalidInput ;
        Operations moveOfCurrentPlayer;
        Player*  currentPlayer ;
    public :
        Board();
        int getBlackCoinCount();
        int getRedCoinCount();
        void setCurrentPlayer(Player*);
        Player* getCurrentPlayer();
        Operations& getCurrentOperation();
        Coin &getCoinRef() ;
};





