#pragma once

#include "./headers/Operations.hpp"

#include<iostream>
using namespace std;

Operations::Operations()
{

}
void Operations::strike(Player* currentPlayer,BlackCoin &blackCoin)
{
    if(blackCoin.getCount()>0)
    {
        blackCoin.updateCount(-1);
        currentPlayer->updateScore(1);
        currentPlayer->resetSuccessiveNoStrikeCount();
    }
    else 
    {
        cout<<endl<<"Black coins are not available";
        currentPlayer->incrementNoSuccessiveStrikeCount();
    }
}
void Operations::multiStrike(Player* currentPlayer,BlackCoin &blackCoin)
{
    if(blackCoin.getCount()>=2)
    {
        currentPlayer->updateScore(2); 
        blackCoin.updateCount(-2);
        currentPlayer->resetSuccessiveNoStrikeCount();
    }
    else
    {
       currentPlayer->incrementNoSuccessiveStrikeCount(); 
    }
}
void Operations::redStrike(Player* currentPlayer,RedCoin& redCoin)
{
    if(redCoin.getCount()>0)
    {
        currentPlayer->updateScore(3);
        redCoin.updateCount(-1);
        currentPlayer->resetSuccessiveNoStrikeCount();
    }
    else
    {
        cout<<endl<<"Red coin is not available ";
        currentPlayer->incrementNoSuccessiveStrikeCount();
    }
}
void Operations::strikerStrike(Player* currentPlayer)
{
    currentPlayer->updateScore(-1);
    //does not pocket a coin
    currentPlayer->incrementNoSuccessiveStrikeCount();
    // looses point
    currentPlayer->incrementFoulCount();
}
void Operations::defunctCoin(Player* currentPlayer,BlackCoin &blackCoin)
{
    if(blackCoin.getCount()>0)
    {
        currentPlayer->updateScore(-2);
        blackCoin.updateCount(-1);
        // does not pocket a coin
        currentPlayer->incrementNoSuccessiveStrikeCount();
        // looses a point
        currentPlayer->incrementFoulCount();
    }
    else
    {
        cout<<"No Black coins are available";
        currentPlayer->incrementNoSuccessiveStrikeCount();
    }
}
void Operations::NoOperation(Player* currentPlayer)
{
    // does not pocket a coin 
    currentPlayer->incrementNoSuccessiveStrikeCount();
}
