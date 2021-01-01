#pragma once
#include "Coin.hpp"

class BlackCoin  : public Coin  
{
    private :
        int count ;
    public : 
        BlackCoin();
        void updateCount(int offset);
        int getCount();
};