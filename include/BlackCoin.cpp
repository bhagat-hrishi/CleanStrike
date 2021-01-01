#pragma once

#include "headers/BlackCoin.hpp"


BlackCoin::BlackCoin()
{
    count = 9;
}

void BlackCoin::updateCount(int offset)
{
    count +=offset;
}
int BlackCoin:: getCount()
{
    return count;
}


