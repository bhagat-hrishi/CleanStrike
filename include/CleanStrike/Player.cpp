#include "./headers/Player.hpp"

Player :: Player()
{
    score=0;
    foulCount = 0;
    noSuccessiveStrikeCount  = 0;
}

int Player:: getScore()
{
     return score;
}

void Player:: setPlayerName(string nameArgument)
{
    this->playerName = nameArgument;
}

string Player::getName()
{
    return playerName;
}

void Player:: updateScore(int offset)
{
    score += offset;
    if(score<=0)
        score = 0;
}

int Player:: getFoulCount()
{
    return foulCount;
}

void Player:: incrementFoulCount()
{
    foulCount ++;
    // when foul==3 player looses additional point
    if(foulCount==3)
    {
        score -- ;
        resetFoulCount();
    }
}

void Player:: resetFoulCount()
{
    foulCount = 0;
}

void Player:: resetSuccessiveNoStrikeCount()
{
    noSuccessiveStrikeCount = 0;
}

void Player:: incrementNoSuccessiveStrikeCount()
{
    noSuccessiveStrikeCount++;
    if(noSuccessiveStrikeCount==3)
    {
        score--;
        resetSuccessiveNoStrikeCount();
    }
}

int Player::getNoSuccessiveStrikeCount()
{
    return noSuccessiveStrikeCount;
}






