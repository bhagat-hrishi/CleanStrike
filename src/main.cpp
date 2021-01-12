#include<iostream>

#include "../include/CleanStrike/headers/Match.hpp"
#include "../include/CleanStrike/headers/Board.hpp"


#include "utils/removeSpaces.hpp"
#include "utils/takeInput.hpp"


using namespace std;

int main()
{   
    cout<<endl<<BOLD<<CYAN<<"______Welcome To Clean Strike________"<<endl<<RESET;
   
    vector<string>inputs;

    takeInputFromFile("./inputs/inputFile.txt", inputs);

    for(int i=0;i<inputs.size();i+=2)
    {
        vector<string>matchInputs;
        string noOfPlayers = inputs[i];
        removeSpaces(inputs[i+1], matchInputs);
        
        Match newMatch = Match(matchInputs,noOfPlayers);
        newMatch.playMatch();  
    }
    
    return 0;
}