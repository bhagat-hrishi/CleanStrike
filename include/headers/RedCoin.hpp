#pragma once
#include "Coin.hpp"

class RedCoin  : public Coin  
{
    private :
        int count ;
    public : 
        RedCoin();
        void updateCount(int offset);
        int getCount();
};