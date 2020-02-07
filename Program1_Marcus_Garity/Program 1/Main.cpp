/*

Name: Marcus Garity
Class/section: CS201 -0004
Due Date: 6Feb2020
Creation Date: 2Feb2020


****************************** Game Description ********************************************************

Pig is a simple two player dice game, played with one die.
The first player to reach or surpass 50 is the winner.
Each player takes a turn rolling the dice.
They add to the pot with each roll, having to decide to roll again and increase the pot, or cash out. 
The risk being they could lose the amount they’ve accumulated into the pot.

 Special thanks to Proffesor Essymer for providing the Decription.

********************************************************************************************************

****************************** Game Algorithm **********************************************************
1.	Roll the Dice.
    1.	If user rolled a 1,
        i.	The pot gets set to zero
        ii.	The other player goes to step 1.
2.	A roll of 2-6 is added to the pot.
    2.	User can choose to hold or roll again.
        1.	Choice ROLL. Return to Step 1.
        2.	Choice HOLD.
            i.	Increment Player score by the pot amount.
            ii.	Pot gets set to 0.
            iii.	second player gets to roll and goes to Step 1.

 Special thanks to Proffesor Essymer for providing the Algorithm.

********************************************************************************************************

********************************Code That I wanted to use but didn't************************************
http://underthepressure.net/how-to-sleep-in-c/
#include <chrono>
#include <thread>
 std::this_thread::sleep_for(std::chrono::milliseconds(1000));

 I wanted to use this to make the AI slower and more like a human player. Ended up not using.

********************************************************************************************************

*/
#include <iostream>
#include<random>
#include<ctime>
#include<string>
#include<thread>
#include<chrono>

int random(int die) {
    int a = (std::rand()%(die)) + 1;

    return a;
}
void eachTurn(int& current_turn, int& other, char a) {
    bool isplayer;

    std::cout << std::endl;
    std::cout << std::endl;
    isplayer = (a == 'p') ? true : false;
    std::cout << "Score        ";
    if (isplayer) {
        std::cout << "Player Score: " << current_turn;
        std::cout << "       Ai Score:" << other << std::endl;
        std::cout << std::endl;
        std::cout << "Players turn to roll.(Press Enter to Continue)" << std::endl;
        std::cin.get();
    }
    else {
        std::cout << "Player Score: " << other;
        std::cout << "       Ai Score:" << current_turn << std::endl;
        std::cout << std::endl;
        std::cout << "Ai Turn to roll.(Press Enter to Continue)" << std::endl;
        std::cin.get();
    }
    
}
    bool checkValid(std::string a) {
        bool isValid;
        isValid = (a=="R"|| a == "r" || a == "H" || a == "h" ) ? true : false;

        return isValid;


}

void turn(int& current_turn,int& other, char a) {
    eachTurn(current_turn,other, a);
    int pot = 0;
    bool isRoll=true;
    bool unlucky = false;
    std::string userInput = "";
    while (isRoll) {
        int die = random(6);
        std::cout << "The die hits the floor and bounces" << std::endl;
        std::cout << "Die is: " << die;
        unlucky = (die==1) ? true : false;
        if (unlucky) {
            pot = 0;
            std::cout << "         Pot: " << pot << std::endl;
            std::cout << "Unlucky roll. End of turn." << std::endl;
            break;
        }
        else {
            pot += die;
            std::cout << "         Pot: " << pot << std::endl;
            while (true) {
                std::cout << "Would you like to Roll again or Hold? (R or H)>>>";
                std::getline(std::cin, userInput);
                if (checkValid(userInput)) {
                    break;
                }
                else
                    continue;
            }
            if (userInput == "R" || userInput == "r") {
                continue;
            }
            else {
                current_turn += pot;
                break;
            }
        }
    
    }

   
}
void aiTurn(int& current_turn, int& other, char a) {
    eachTurn(current_turn, other, a);
    int pot = 0;
    bool isRoll = true;
    bool unlucky = false;
    std::string userInput = "";
    while (isRoll) {
        int die = random(6);
        std::cout << "The die hits the floor and bounces" << std::endl;
        std::cout << "Die is: " << die;
        unlucky = (die == 1) ? true : false;
        if (unlucky) {
            pot = 0;
            std::cout << "         Pot: " << pot << std::endl;
            std::cout << "Unlucky roll. End of turn." << std::endl;
            break;
        }
        else {
            pot += die;
            std::cout << "         Pot: " << pot << std::endl;
            
            if (pot<20) {
                continue;
            }
            else {
                current_turn += pot;
                break;
            }
        }

    }
}




bool game(int& player, int& ai) {
    player = 0;
    ai = 0;
    bool playerWon;
    while (true) {
        

        turn(player,ai,'p');
        if (player >= 50)
            break;
        aiTurn(ai,player,'a');
        
        if (player >= 50 || ai >= 50)
            break;
    }
    playerWon = (player > ai) ? true : false;
    return playerWon;
}

int main() {

    int playerScore=0;
    int aiScore=0;
    bool playerWon;
    std::string userInput;
    bool userInvalid;
    bool userPlay=true;

    std::cout << "Welcome to the Die game called Pig." << std::endl;
    std::cout << "****************************************RULES OF GAME*********************************************" << std::endl;
    std::cout<<" Pig is a simple two player dice game, played with one die.                                         "<<std::endl;
    std::cout<<" The first player to reach or surpass 50 is the winner.                                             "<<std::endl;
    std::cout<<" Each player takes a turn rolling the dice.                                                         "<<std::endl;
    std::cout<<" They add to the pot with each roll, having to decide to roll againand increase the pot, or cash out"<<std::endl;
    std::cout<<" The risk being they could lose the amount they’ve accumulated into the pot.                        "<<std::endl;
    std::cout << "****************************************************************************************************" << std::endl;
    while (userPlay) {
        std::srand(std::time(NULL));
        userInvalid = true;
        playerWon = game(playerScore,aiScore);

        std::cout << std::endl;
        std::cout << std::endl;
        if (playerWon) {
            std::cout << "PLAYER WON!!!!" << std::endl;
            std::cout << "Player Score: " << playerScore;
            std::cout << "           Ai Score: " << aiScore << std::endl;
        }
        else {
            std::cout << "PLAYer lost ._." << std::endl;
            std::cout << "Ai Score: " << aiScore;
            std::cout << "           Player Score: " << playerScore << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::endl;

        while (userInvalid) {
            std::cout << "Does player want to play again?(Y or N) >>>>";
            std::cin>>userInput;
            std::cout << std::endl;
            if (userInput == "Y" || userInput == "N" || userInput == "y" || userInput == "n") {
                userInvalid = false;
                userPlay = ((userInput == "Y")||(userInput =="y")) ? true : false;
                std::cin.get();
            }
            else {
                std::cout << "Invalid input, try again :)" << std::endl;
                userInvalid = true;
            }
        } 
    }
    





    std::cout << "Press Enter to exit program!";
    std::cin.get();
    


    return 0;
}



