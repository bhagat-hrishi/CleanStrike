#pragma once

#include "headers/Board.hpp"
#include "headers/BlackCoin.hpp"
#include "headers/RedCoin.hpp"

// Board cpp 
Board::Board()
{

}
int Board::getBlackCoinCount()
{
    return blackCoin.getCount();
}
int Board::getRedCoinCount()
{
    return redCoin.getCount();
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
BlackCoin& Board::getBlackCoinRef()
{
    return blackCoin;
}
RedCoin& Board::getRedCoinRef()
{
    return redCoin;
}