#include <gtest/gtest.h> 

#include "../include/CleanStrike/headers/Player.hpp"
#include "../include/CleanStrike/headers/Coin.hpp"
#include "../include/CleanStrike/headers/Operations.hpp"

// creating fixture 
struct OperationsTest : public testing::Test
{
   Operations*  currentOperation ;
   Player currentPlayer = Player();
   Coin coin = Coin();

   void SetUp()
   {
       currentOperation = new Operations();
    //    currentOperation->strike(&currentPlayer,coin);
   }

   void TearDown()
   {
       delete currentOperation;
   }
};


TEST_F(OperationsTest,strikeOperationTest)
{
    int initialScore = currentPlayer.getScore();
    currentOperation->strike(&currentPlayer,coin);

    ASSERT_EQ(coin.getBlackCount(), 8 );
    ASSERT_EQ(currentPlayer.getScore(),initialScore+1);
}

TEST_F(OperationsTest,multiStrikeOperationTest)
{
    int initialScore = currentPlayer.getScore();
    int initialBlackCoin = coin.getBlackCount();
    currentOperation->multiStrike(&currentPlayer , coin);


    ASSERT_EQ(coin.getBlackCount(),initialBlackCoin-2);
    ASSERT_EQ(currentPlayer.getScore(),initialScore+2);
}

TEST_F(OperationsTest , redStrikeOperationTest)
{
    int initialScore = currentPlayer.getScore();
    currentOperation->redStrike(&currentPlayer,coin);
    
    ASSERT_EQ(coin.getRedCount(),0);
    ASSERT_EQ(currentPlayer.getScore(),initialScore+3);
}
   
TEST_F(OperationsTest , strikerStrikeOperationTest)
{
    int initialBlackCount = coin.getBlackCount();
    currentOperation->strikerStrike(&currentPlayer);

    ASSERT_EQ(coin.getBlackCount(),initialBlackCount);
    ASSERT_EQ(coin.getRedCount(),1);
    ASSERT_EQ(currentPlayer.getScore(),0);
}

TEST_F(OperationsTest , defunctCoinOperationTest)
{
    currentOperation->defunctCoin(&currentPlayer , coin);

    ASSERT_EQ(coin.getBlackCount(),8);
    ASSERT_EQ(currentPlayer.getNoSuccessiveStrikeCount(),1);
    ASSERT_EQ(currentPlayer.getFoulCount(),1);
}


// TEST_F()
// {

// }