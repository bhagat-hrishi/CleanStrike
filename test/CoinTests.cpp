#include <gtest/gtest.h>

#include "../include/CleanStrike/headers/Coin.hpp"

struct CoinTest : public testing::Test 
{
    Coin *coin;

    void SetUp()
    {
        coin = new Coin();
    }
    void TearDown()
    {
        delete coin;
    }

};

TEST_F(CoinTest, initialCoinCountTest)
{
    ASSERT_EQ(coin->getRedCount(),1);
    ASSERT_EQ(coin->getBlackCount(),9);
}

TEST_F(CoinTest,decrementBlackCoinCountBy1)
{
    int initialBlackCount = coin->getBlackCount();
    coin->updateBlackCount(-1);
    ASSERT_EQ(coin->getBlackCount(),initialBlackCount-1);
}

TEST_F(CoinTest,decrementRedCoinCountBy1)
{
    coin->updateRedCount(-1);
    ASSERT_EQ(coin->getRedCount(),0);
}


