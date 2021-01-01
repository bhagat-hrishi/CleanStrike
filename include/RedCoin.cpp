#pragma once

#include "headers/RedCoin.hpp"


RedCoin::RedCoin()
{
    count = 1;
}

void RedCoin::updateCount(int offset)
{
    count +=offset;
}
int RedCoin:: getCount()
{
    return count;
}


