//Conner Keiter Program 1 for CS201
#include <iostream>
#include <ctime>
using namespace std;

void game();
void output_score();
int dice_roll();
int player_turn();
int AI_turn();


//variables to hold hold score

//creating game count variable to keep track of who should start in each game because it should alternate starting player
int gamecount = 0 ;
int player1=0,player2=0;

int main() {
    char play = 'Y';
    //continues game play until user says not to
    while (play == 'Y') {
        game();
        cout << "Do you want to play again? (Y)es or (N)o  ";
        cin >> play;
        cout << endl;
        play = toupper(play);
        while (!(play == 'Y' || play == 'N')){
            cout << " YOU MUST CHOOSE Y OR N TO PLAY ";
            cin>> play;
            play = toupper(play);
            cout<< endl;
        }
        gamecount +=1;
    }
    cout << "Thank you for playing.";
}

void game() {
    player1=0, player2=0;
    bool not1 = true;
    bool not2 = true;
    
    output_score();
    
    //continues to loop as long as nobody has one
    while(not1 && not2 ) {
        if (gamecount%2 == 0){
            cout << endl;
            cout << "Players turn \n";
            player1 += player_turn();
            //score of 50 or above will break the loop
            if (player1 >= 50) {
                not1=false;
            }
            else {
                cout << endl;
                output_score();
                cout << endl;
                cout << "AIs turn \n";
                player2 += AI_turn();
                cout << endl;
                //score of 50 or greater will break the loop
                if (player2 >= 50) {
                    not2 = false;
                }
            }
        }
        if (gamecount%2 == 1){
            cout << endl;
            cout << "AI turn \n";
            player2 += AI_turn();
            //score of 50 or above will break the loop
            if (player2 >= 50) {
                not2=false;
            }
            else {
                cout << endl;
                output_score();
                cout << endl;
                cout << "Players turn \n";
                player1 += player_turn();
                cout << endl;
                //score of 50 or greater will break the loop
                if (player1 >= 50) {
                    not1 = false;
                }
            }
        }
        output_score();
    }
    //this if-else decides and displays who won
    if (!not1){
            cout << "Player 1 wins!\n";
        }
    else {
            cout << "AI wins! \n";
        }
}

//general formula to output the current score
void output_score() {
    cout << "Score  You: " << player1 << " AI " << player2 <<endl;
}


//uses random function to produce pseudorandom numbers
int dice_roll() {
    int val;
    val = (rand()%6)+1 ;
    return val;
}

//loops to allow for players turn until they input H for hold
int player_turn() {
    char playChar = 'R';
    int pot = 0;
    int dice;
    
    dice = dice_roll();
    while (dice != 1 && playChar == 'R') {
        pot += dice;
        cout << "Die Roll : " << dice << "  Pot : " << pot <<"   (R)oll again or (H)old? " ;
        cin >> playChar;
        playChar = toupper(playChar);
        
        //validates user input of H or R
        while (playChar != 'H' && playChar != 'R') {
            cout << endl;
            cout << "You must enter R or H \n \t (R)oll again or (Hold) " ;
            cin >> playChar;
            playChar = toupper(playChar);
        }
        if (playChar=='H') {
            return pot;
        }
        dice = dice_roll();
    }
    if (dice == 1 ){
        cout << "Die Roll 1 : BUST\n";
        return 0;
    }
    return pot;
}

//AI Turn Adds to the pot as long as the pot is less than or equal to 20 per program instructions
int AI_turn() {
    int pot = 0;
    int dice;
    
    dice = dice_roll();
    while (dice != 1 && pot <=20) {
        pot += dice;
        cout << "Die Roll : " << dice << "  Pot : " << pot ;
        cout << endl;
        dice = dice_roll();
    }
    if (dice == 1 ){
        cout << "Die Roll 1 : BUST\n";
        return 0;
    }
    return pot;
}
