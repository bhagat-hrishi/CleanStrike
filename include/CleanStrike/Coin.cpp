#include "headers/Coin.hpp"


Coin::Coin()
{
    redCoin = 1;
    blackCoin = 9;
}
void Coin::updateRedCount(int offset)
{
    redCoin += offset;
    if(redCoin < 0)
        redCoin = 0;
}
void Coin::updateBlackCount(int offset)
{
    blackCoin += offset;
    if(blackCoin<0)
        blackCoin = 0;
}
int Coin::getRedCount()
{
    return redCoin;
}
int Coin::getBlackCount()
{
    return blackCoin;
}



