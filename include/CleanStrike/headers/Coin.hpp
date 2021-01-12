#pragma once

class Coin 
{
    int redCoin;
    int blackCoin;
    public :
        Coin();
        void updateRedCount(int offset);
        void updateBlackCount(int offset);
        int getRedCount();
        int getBlackCount();
};
