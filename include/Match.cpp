#pragma once
#ifndef MYFILE_H
#define MYFILE_H
#include "headers/VariadicTable.h"
#include "headers/Match.hpp"
#include "headers/Board.hpp"
#endif


// for colors inside match.cpp
#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


#define FRED(x) KRED x RST //red
#define FGRN(x) KGRN x RST //green
#define FYEL(x) KYEL x RST //yellow
#define FBLU(x) KBLU x RST //blue
#define FMAG(x) KMAG x RST //MAGENTA
#define FCYN(x) KCYN x RST //CYAN
#define FWHT(x) KWHT x RST //white


#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */
// colors end


#include<iostream>
#include <string>
using namespace std;

int Match::activePlayer = 0; 

Match::Match()
{
    string name;

    cout<<endl<<"Enter Count of Players : ";
    cin>>playersCount ;
    for(int i=0;i<playersCount;i++)
    {
        Player tmpPlayer;
        players.push_back(tmpPlayer);
        cout<<endl<<FMAG("Enter Name of  ")<< i+1 <<FMAG( " player :");
        players[i].setPlayerName();
    }

    cout<<endl<<BOLD(FCYN("______Welcome To Clean Strike________"))<<endl;

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
    cout<<endl<<FWHT("Remaining Black Coins :")<<board.getBlackCoinCount();
    cout<<endl<<FRED("Remaining Red Coin :")<<board.getRedCoinCount()<<endl;

}
bool Match::isMatchOver()
{
    int player1Score = players[0].getScore();
    int player2Score = players[1].getScore();

    if(player1Score>=5 && ((player1Score-player2Score)>=3))
    {
        cout<<endl<<"Player "<<players[0].getName()<<" won the game. Final Score:"<<player1Score<<" - "<<player2Score;
        showPlayersScore();
        showRemainingCoins();
        return true;
    }
    else if(player2Score>=5 && ((player2Score-player1Score)>=3))
    {
        cout<<endl<<"Player "<<players[1].getName()<<" won the game. Final Score:"<<player2Score<<" - "<<player1Score;
        showPlayersScore();
        showRemainingCoins();
        return true;
    }
    else if(invalidInputs>=10)
    {
        cout<<endl<<FCYN("Match ended due to  many invlid Inputs ");
        showPlayersScore();
        
        return true;
    }
    else if(board.getBlackCoinCount()==0 && board.getRedCoinCount()==0)
    {
        cout<<endl<<BOLD(FCYN("Match Draw "));
        showPlayersScore();
        showRemainingCoins();
        return true;

    }
    else if(board.getBlackCoinCount()<0 && board.getRedCoinCount()<0)
    {
        cout<<endl<<BOLD(FCYN("Coins are not Available"));
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
        cout<<endl<<string((board.getCurrentPlayer())->getName())<<" : Choose an outcome from the list below";
        cout<<endl<<FGRN("1. Strike");
        cout<<endl<<FYEL("2. Multistrike");
        cout<<endl<<FRED("3. Red strike");
        cout<<endl<<FCYN("4. Striker strike");
        cout<<endl<<FMAG("5. Defunct coin");
        cout<<endl<<FBLU("6. None"); 
        cout<<endl<<"==> ";
    
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
                cout<<endl<<FRED("Plese Provide Valid Invalid Input");
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
