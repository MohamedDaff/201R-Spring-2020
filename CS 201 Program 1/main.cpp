//
//
//  main.cpp
//  CS 201 Program 1
//
//  Created by Davith Lon on 1/30/20.
//  Copyright © 2020 Davith Lon. All rights reserved.
//
//
#include <iostream>
#include <ctime>
using namespace std;

//Function Prototypes------------------------------------------------
void score_update();
char user_selection();
void roll_dice();
void humanTurn ();
void play_again ();
void computerTurn();
char computerSelectionRoll();

//Global Variables----------------------------------------------------
bool program_status = false;
bool gameStatus = false;
int playerScore;
int computerScore;
int dieRoll;
int gamePotTotal;
bool playerStatus;
int playerTurn = 0;

//Main-----------------------------------------------------------------
int main() {
    srand(time(0)); // Seeds the rand function to time(0).
    
    do{
        gamePotTotal = 0;
        playerScore = 0;
        computerScore = 0;
        
        while(playerScore < 50 && computerScore < 50){ // Keeps the game going until there is a winner.
        
            if (playerTurn == 0){// Player's turn
                score_update();
                cout << "Human's Turn" << endl;
                humanTurn();
                if(playerScore >= 50){
                    break;
                }
                gamePotTotal = 0;
                playerTurn += 1;
            }
            else if (playerTurn == 1){ // Computer's turn
                score_update();
                cout << "Computer Turn" << endl;
                computerTurn();
                if(computerScore >= 50){
                    break;
                }
                gamePotTotal = 0;
                playerTurn -= 1;
            }
        }
        
        score_update();
        
        if (playerTurn == 0){
            cout << "The Winner is the Human!" << endl;
            playerTurn = 1;
        }
        else if (playerTurn == 1){
            cout << "The Winner is the Computer!" << endl;
            playerTurn = 0;
        }
        play_again();
        
    } while (program_status == false);
    
    return 0;
}
//Function Definitions--------------------------------------------------------
void humanTurn (){ // Actions in during the Player's turn.
    
    char player_selection;
    playerStatus = false;
    
    do{
    
        roll_dice();
        
       if (dieRoll == 1){
           cout << "Die Roll 1 : BUST " << endl;
           gamePotTotal = 0;
           playerStatus = true;
           return;
       }
        
        player_selection = user_selection();
        
        if (gamePotTotal >= 50){
            player_selection = 'H';
        }
        
        if (player_selection == 'R'){
            humanTurn();
        }
        
        else if (player_selection == 'H'){
            playerScore += gamePotTotal;
            playerStatus = true;
        }
        
    } while (playerStatus == false);
}
//--------------------------------------------------------------------
void roll_dice(){ // Assigns a random value to the dieRoll variable.
    
    dieRoll = ((rand() % 6) + 1) ;
    gamePotTotal += dieRoll;
    
}
//--------------------------------------------------------------------
char user_selection(){ // Gets the player selection on wheather or not to continue rolling or cash out their pot for points.
    
    char input;
    
    cout << "Die Roll : " << dieRoll << " Pot : " << gamePotTotal << "\t(R)oll again or (H)old? ";
    cin >> input;
    
    input = toupper(input);
    
    while(input != 'R' && input != 'H'){
           cout << "You must enter a valid input" << endl;
           cin >> input;
           input = toupper(input);
       }
    
    return input;
}
//--------------------------------------------------------------------
void score_update(){ // prints out the updated score.
    
    cout << endl << "Score  You : " << playerScore << " AI : " << computerScore << endl << endl;
}
//--------------------------------------------------------------------
void play_again (){ // Sees if the player wants to play again or quit the program.
    
    char selection;
    
    cout << "Would you like to play again? (Y/N)" << endl;
    
    cin >> selection;
    
    selection = toupper(selection);
    
    while(selection != 'Y' && selection != 'N'){
           cout << "You must enter a valid input" << endl;
           cin >> selection;
           selection = toupper(selection);
       }
        
        if (selection == 'N' || selection == 'n'){
            program_status = true;
        }
        else{
            program_status = false;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        }
        
}
//--------------------------------------------------------------------
void computerTurn(){// Actions during the Computer's turn.
    
    char computerSelection;
    
    roll_dice();
    
    if (dieRoll == 1){
        cout << "Die Roll 1 : BUST " << endl;
        gamePotTotal = 0;
        return;
    }
    
    computerSelection = computerSelectionRoll();
        if(gamePotTotal < 20){
            computerTurn();
        }
        else if (gamePotTotal >= 20) {
            computerScore += gamePotTotal;
            return;
        }
}
//--------------------------------------------------------------------
char computerSelectionRoll(){ // The purpose of this function is to force the Computer to roll again.
    
    cout << "Die Roll : " << dieRoll << " Pot : " << gamePotTotal << endl;
    
    return 'Y';
}
//--------------------------------------------------------------------
