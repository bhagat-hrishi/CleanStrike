#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "../include/CleanStrike/headers/Match.hpp"
#include "../include/CleanStrike/headers/Board.hpp"
#include "../include/CleanStrike/headers/Player.hpp"


// Create a Fixture for Match class
struct MatchTest: public testing::Test
{
    // Arrange
    Match *match;

    Player player = Player();
    std::vector<std::string> input = {"1", "1", "1", "1", "2", "2", "3"};

   
    void SetUp() 
    {
        match = new Match(input, "2");
        match->getBoard().setCurrentPlayer(&player);
        // cout<<endl<<"setup done"<<endl;
    }
    void TearDown()
    {
        // cout<<endl<<"TearDown done"<<endl;
        delete match;
    }
};

TEST_F(MatchTest, firstPlayerWinsTest) {
    // Arrange
    Match match = Match({"player1", "player2", "1", "1", "3", "6", "2", "6", "2"}, "2");

    // Apply
    match.playMatch();

    // Assert
    ASSERT_STREQ(match.getGameResult().c_str(), "Player 1 Wins");
}

TEST_F(MatchTest, secondPlayerWinsTest) {
    // Arrange
    Match match = Match({"player1", "player2","1", "3", "6", "2", "6", "1", "3"}, "2");

    // Apply
    match.playMatch();

    // Assert
    ASSERT_STREQ(match.getGameResult().c_str(), "Player 2 Wins");
}

TEST_F(MatchTest, gameDrawTest) {
    // Arrange
    Match match = Match({"player1", "player2","3", "2", "6", "1", "2", "2", "1", "2", "1"}, "2");

    // Apply
    match.playMatch();

    // Assert
    ASSERT_STREQ(match.getGameResult().c_str(), "GameDraw");
}

TEST_F(MatchTest, tooManyInvalidInputsTest) {
    // Arrange
    Match match = Match({
        "player1", "player2","7", "8", "a", "b", "#", "100", "402", "abc", "A",
        "2323", "@34", "o04#", "312", "111", "2323323", "232",
        "1#E", "3AJK", "MP"
    }, "2");

    // Apply
    match.playMatch();

    // Assert
    ASSERT_STREQ(match.getGameResult().c_str(), "TooManyInvalidInputs");
}




