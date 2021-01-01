
#ifndef MYFILE_H
#define MYFILE_H
#include "headers/VariadicTable.h"
#include "headers/Match.hpp"
#include "headers/Board.hpp"
#endif


#include<iostream>
#include <string>
using namespace std;

int Match::activePlayer = 0; 

Match::Match()
{
    string name;

    cout<<endl<<CYAN<<"Enter Count of Players : "<<RESET;
    cin>>playersCount ;
    for(int i=0;i<playersCount;i++)
    {
        Player tmpPlayer;
        players.push_back(tmpPlayer);
        cout<<endl<<MAGENTA<<"Enter Name of  "<<RESET<< i+1<<MAGENTA << " player : "<<RESET;
        players[i].setPlayerName();
    }

    cout<<endl<<BOLD<<CYAN<<"______Welcome To Clean Strike________"<<endl<<RESET;

    result = "";
    invalidInputs = 0;
    board.setCurrentPlayer(&(players[activePlayer]));

}

void Match::changePlayer()
{
    if(activePlayer<=playersCount-2)
        activePlayer++;
    else 
        activePlayer = 0;
    
    // cout<<"\nactivePlayer: "<<activePlayer;
    board.setCurrentPlayer(&(players[activePlayer]));
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
bool Match::isMatchOver()
{
    int player1Score = players[0].getScore();
    int player2Score = players[1].getScore();

    if(player1Score>=5 && ((player1Score-player2Score)>=3))
    {
        cout<<endl<<GREEN<<"Player "<<RESET<<CYAN<<players[0].getName()<<RESET<<GREEN<<" won the game. Final Score: "<<RESET<<BLUE<<player1Score<<" - "<<player2Score<<RESET;
        showPlayersScore();
        showRemainingCoins();
        return true;
    }
    else if(player2Score>=5 && ((player2Score-player1Score)>=3))
    {
        cout<<endl<<GREEN<< "Player "<<RESET<<CYAN<<players[1].getName()<<RESET<<GREEN<<" won the game. Final Score: "<<RESET<<BLUE<<player2Score<<" - "<<player1Score<<RESET;
        showPlayersScore();
        showRemainingCoins();
        return true;
    }
    else if(invalidInputs>=10)
    {
        cout<<endl<<CYAN<<"Match ended due to  many invlid Inputs "<<RESET;
        showPlayersScore();
        showRemainingCoins();
        return true;
    }
    else if(board.getBlackCoinCount()==0 && board.getRedCoinCount()==0)
    {
        
        cout<<endl<<CYAN<<BOLD<<"Match Draw "<<RESET;
        showPlayersScore();
        showRemainingCoins();
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

void Match::playMatch()
{
    while(1)
    {
        
        // as currentPlayer is pointer
        cout<<endl<<BLUE<<(board.getCurrentPlayer())->getName()<<RESET<<CYAN<<" : Choose an outcome from the list below "<<RESET;
        cout<<endl<<GREEN<< "1. Strike"<<RESET;
        cout<<endl<<BLUE<<"2. Multistrike"<<RESET;
        cout<<endl<<RED<< "3. Red strike"<<RESET;
        cout<<endl<<CYAN<<"4. Striker strike"<<RESET;
        cout<<endl<<MAGENTA<<"5. Defunct coin"<<RESET;
        cout<<endl<<DARKGRAY<<"6. None"<<RESET; 
        cout<<endl<<GREEN<<"==> "<<RESET;
    
        int inputOption;
        cin>>inputOption;

        switch (inputOption)
        {
            case 1:
                board.getCurrentOperation().strike(board.getCurrentPlayer(),board.getBlackCoinRef());
                break;
            case 2:
                board.getCurrentOperation().multiStrike(board.getCurrentPlayer(),board.getBlackCoinRef());
                break;
            case 3:
                board.getCurrentOperation().redStrike(board.getCurrentPlayer(),board.getRedCoinRef());
                break;
            case 4:
                board.getCurrentOperation().strikerStrike(board.getCurrentPlayer());
                break;
            case 5:
                board.getCurrentOperation().defunctCoin(board.getCurrentPlayer(),board.getBlackCoinRef());
                break;
            case 6:
                board.getCurrentOperation().NoOperation(board.getCurrentPlayer());
                break;
            default:
                cout<<endl<<RED<<BOLD<<"Plese Provide Valid  Input"<<endl<<RESET;
                incrementInvalidInputs();
                break;
        }

        // to change player
        changePlayer();
        
        // check if game is Over
         if(isMatchOver())
            break;
    
    }
}

Match::~Match()
{
    players.clear();
}
