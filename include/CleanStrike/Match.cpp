#ifndef MYFILE_H
#define MYFILE_H
#include "headers/VariadicTable.h"
#include "headers/Match.hpp"
#include "headers/Board.hpp"
#endif

#include<iostream>
#include <string>
using namespace std;

Match::Match()
{

}

Match::Match(std::vector<std::string> input, std::string noOfPlayers)
{
    string name;
    // cout<<endl<<CYAN<<"Enter Count of Players : "<<RESET;
    // cin>>playersCount ;

    this->input = input;
    this->playersCount  = stoi(noOfPlayers);

    for(int i=0;i<playersCount;i++)
    {
        Player tmpPlayer;
        players.push_back(tmpPlayer);
        // cout<<endl<<MAGENTA<<"Enter Name of  "<<RESET<< i+1<<MAGENTA << " player : "<<RESET;
        players[i].setPlayerName(input[i]);
    }

    

    result = "";
    invalidInputs = 0;

    // Set currne player as 
    activePlayer = 0;


    board.setCurrentPlayer(&(players[activePlayer]));

}

void Match::changePlayer(int activePlayerArgument)
{

    if(activePlayerArgument==playersCount)
        this->activePlayer = 0;
    
    // cout<<"\n Inside change : activePlayer: "<<this->activePlayer;
    board.setCurrentPlayer(&(players[this->activePlayer]));
}

void Match::playMatch()
{
    
    for(int i=playersCount ; i<input.size();i++)
    {
        // as currentPlayer is pointer
        // cout<<endl<<BLUE<<(board.getCurrentPlayer())->getName()<<RESET<<CYAN<<" : Choose an outcome from the list below "<<RESET;
        // cout<<endl<<GREEN<< "1. Strike"<<RESET;
        // cout<<endl<<BLUE<<"2. Multistrike"<<RESET;
        // cout<<endl<<RED<< "3. Red strike"<<RESET;
        // cout<<endl<<CYAN<<"4. Striker strike"<<RESET;
        // cout<<endl<<MAGENTA<<"5. Defunct coin"<<RESET;
        // cout<<endl<<DARKGRAY<<"6. None"<<RESET; 
        // cout<<endl<<GREEN<<"==> "<<RESET;
    
        // int inputOption ;
        // cin>>inputOption;

        if(input[i] == "1")
        {
            board.getCurrentOperation().strike(board.getCurrentPlayer(),board.getCoinRef());
        }
        else if(input[i] == "2")
        {
            board.getCurrentOperation().multiStrike(board.getCurrentPlayer(),board.getCoinRef());
        }
        else if(input[i]== "3")
        {
            board.getCurrentOperation().redStrike(board.getCurrentPlayer(),board.getCoinRef());
        }
        else if(input[i] == "4")
        {
            board.getCurrentOperation().strikerStrike(board.getCurrentPlayer());
        }
        else if(input[i] == "5")
        {
            board.getCurrentOperation().defunctCoin(board.getCurrentPlayer(),board.getCoinRef());
        }
        else if(input[i] == "6")
        {
            board.getCurrentOperation().NoOperation(board.getCurrentPlayer());
        }
        else
        {
            cout<<endl<<RED<<BOLD<<"Plese Provide Valid  Input"<<endl<<RESET;
            incrementInvalidInputs();
        }
        

        // to change player
        activePlayer++;
       
        changePlayer(activePlayer);
        
        // check if game is Over
         if(isMatchOver())
            break;
    
    }
}



bool Match::isMatchOver()
{
    int player1Score = players[0].getScore();
    int player2Score = players[1].getScore();

    if(player1Score>=5 && ((player1Score-player2Score)>=3))
    {
        cout<<endl<<GREEN<<"Player "<<RESET<<CYAN<<players[0].getName()<<RESET<<GREEN<<" won the game. Final Score: "<<RESET<<BLUE<<player1Score<<" - "<<player2Score<<RESET;
        showPlayersScore();
        showRemainingCoins();
        result = "Player 1 Wins";
        return true;
    }
    else if(player2Score>=5 && ((player2Score-player1Score)>=3))
    {
        cout<<endl<<GREEN<< "Player "<<RESET<<CYAN<<players[1].getName()<<RESET<<GREEN<<" won the game. Final Score: "<<RESET<<BLUE<<player2Score<<" - "<<player1Score<<RESET;
        showPlayersScore();
        showRemainingCoins();
        result = "Player 2 Wins";
        return true;
    }
    else if(invalidInputs>=10)
    {
        cout<<endl<<CYAN<<"Match ended due to  many invlid Inputs "<<RESET;
        showPlayersScore();
        showRemainingCoins();
        result = "TooManyInvalidInputs";
        return true;
    }
    else if(board.getBlackCoinCount()==0 && board.getRedCoinCount()==0)
    {
        
        cout<<endl<<CYAN<<BOLD<<"Match Draw "<<RESET;
        showPlayersScore();
        showRemainingCoins();
        result = "GameDraw";
        return true;

    }
    else if(board.getBlackCoinCount()<0 && board.getRedCoinCount()<0)
    {
        cout<<endl<<CYAN<<BOLD<<"Coins are not Available"<<RESET;
        showPlayersScore();
        return true;
    }
    return false;
}

void Match::incrementInvalidInputs()
{
    invalidInputs++;
}

bool Match::comparePlayerByScore(Player player1,Player player2)
{
    return player1.getScore() > player2.getScore();
}

void Match::showPlayersScore()
{   
    // sort players by score in descending
    sort(players.begin(),players.end(),comparePlayerByScore);

    // setup for table start
    VariadicTable<std::string,int> scoreTable({"Player Name","Score"});
    scoreTable.setColumnFormat({
        
        VariadicTableColumnFormat::AUTO ,  
        VariadicTableColumnFormat::AUTO
    });
    // setup for table end

    for(int index = 0;index<playersCount;index++)
    {
        scoreTable.addRow(players[index].getName(),players[index].getScore());
    }

    // print table
    cout<<endl;
    scoreTable.print(std::cout);
}

void Match::showRemainingCoins()
{
    cout<<endl<<WHITE<<"Remaining Black Coins : "<<board.getBlackCoinCount()<<RESET;
    cout<<endl<<  RED<<"Remaining Red Coin    : "<<board.getRedCoinCount()<<RESET<<endl;

}

string Match::getGameResult()
{
    return result;
}
Board Match::getBoard()
{
    return this->board;
}

Match::~Match()
{
    players.clear();
}
