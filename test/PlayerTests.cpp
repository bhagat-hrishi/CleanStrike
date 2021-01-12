/*
    Test Related To Score - 25 to 47
    Test Related To FoulCount - 48 to 68
    Test Related To NoSuccessiveStrikeCount - 71 to 91
    Test Related To PlayerName -  94
*/
#include <gtest/gtest.h> 
#include "../include/CleanStrike/headers/Player.hpp"
#include <string>

// Creating fixture for player class
struct PlayerTest : public testing::Test 
{
    Player *player;

    void SetUp()
    {
        player = new Player();
    }
    void TearDown()
    {
        delete player;
    }

};

TEST_F(PlayerTest , intilialScoreTest)
{
    // act 
        int intialScore = player->getScore();
    // assert test 
        ASSERT_EQ(intialScore , 0);
}
TEST_F(PlayerTest ,  ScoreIncrementBy2Test)
{
    // act 
        player->updateScore(2);
    // assert test 
        ASSERT_EQ(player->getScore(),2);
}

TEST_F(PlayerTest ,  ScoreLessThanZeroTest)
{
       // act 
        player->updateScore(-2);
    // assert test 
        ASSERT_EQ(player->getScore(),0);
}

TEST_F(PlayerTest , initialFoulCountTest)
{
    // act 
        int initialFoulCount =  player->getFoulCount();
    // assert test 
        ASSERT_EQ(initialFoulCount,0);
}
TEST_F(PlayerTest , incrementFoulCountTest)
{
    // act
        player->incrementFoulCount();
    // assert 
        ASSERT_EQ(player->getFoulCount(),1);
}
TEST_F(PlayerTest ,resetFoulCountTest)
{
    // act
        player->resetFoulCount();
    // assert 
        ASSERT_EQ(player->getFoulCount(),0);
}

TEST_F(PlayerTest , initialNoSuccessiveStrikeCountTest)
{
    // act 
        int initialNoSuccessiveStrikeCount =  player->getNoSuccessiveStrikeCount();
    // assert test 
        ASSERT_EQ(initialNoSuccessiveStrikeCount,0);
}
TEST_F(PlayerTest , incrementNoSuccessiveStrikeCountTest)
{
    // act 
        player->incrementNoSuccessiveStrikeCount();
    // assert test 
        ASSERT_EQ(player->getNoSuccessiveStrikeCount(),1);
}
TEST_F(PlayerTest , resetNoSuccessiveStrikeCountTest)
{
    // act 
        player->resetSuccessiveNoStrikeCount();
    // assert test 
        ASSERT_EQ(player->getNoSuccessiveStrikeCount(),0);
}


TEST_F(PlayerTest , PlayerNameTest)
{
    // act 
        string playerName = "Hrishi";
        player->setPlayerName(playerName);
    // assert test 
        ASSERT_STREQ(player->getName().c_str() ,"Hrishi");
}








