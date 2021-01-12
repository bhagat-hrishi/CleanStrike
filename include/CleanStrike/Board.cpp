#pragma once

#include "headers/Board.hpp"
#include "headers/Coin.hpp"

// Board cpp 
Board::Board()
{

}
int Board::getBlackCoinCount()
{
    return coin.getBlackCount();
}
int Board::getRedCoinCount()
{
    return coin.getRedCount();
}
void Board::setCurrentPlayer(Player* currentPlayer)
{
    this->currentPlayer = currentPlayer;
}
Player* Board::getCurrentPlayer()
{
    return currentPlayer;
}
Operations& Board::getCurrentOperation()
{
    return moveOfCurrentPlayer;
}
Coin& Board::getCoinRef()
{
    return coin;
}

