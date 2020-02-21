//Morgan Rogers
//CS201R Program 1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




void OutputScore(int player1score, int AIscore) { //outputs score for both players
	cout << "SCORE----You: " << player1score << " AI: " << AIscore << "----" << endl;
}


int main() {
	int player1pot = 0;
	int player1score = 0;
	int AIpot = 0;
	int AIscore = 0;
	int AIRoll = 0;
	bool playerwon = false;
	char playAgain = 't';
	char answer;
	int randRoll;

	srand(time(0));
	while (true) {
		cout << "Welcome to Pig Dice Game" << endl;
		while (true) {                              //Players turn
			cout << endl;
			OutputScore(player1score, AIscore);
            cout << "Players Turn" << endl;
			while (true) {
				cout << "Rolling dice..." << endl;
				randRoll = (rand() % 6) + 1;
				if (randRoll == 1) {
					player1pot = 0;
					cout << "Die Roll: " << randRoll << "   Pot: " << player1pot << endl;
					cout << "UH OH, Die Roll 1 - AI's turn" << endl;
					cout << endl;
					break;
				}
				player1pot += randRoll;
				cout << "Die Roll: " << randRoll << "   Pot: " << player1pot << endl;
				

				while (true) { //ASK PLAYER TO ROLL OR HOLD
					cout << "(R)oll again or (H)old? " << endl;
					cin >> answer;
					if (answer != 'H' && answer != 'h' && answer != 'R' && answer != 'r') {
						cout << "You must enter R or H" << endl;
						continue;
					}
					else if(answer == 'r' || answer == 'R') {
                        break;
					}
					else {
						player1score += player1pot;
						cout << endl;
						break;
					}

				}
				if (player1score >= 50) { //OUTPUT IF PLAYER WON
					cout << "Player 1 Won!!!" << endl;
					OutputScore(player1score, AIscore);
					playerwon = true;
					cout << endl;
					break;
				}
				if (answer == 'r' || answer == 'R') {
					continue;
				}
				else {
					break;
				}
            }
			while (true) {  //CHECK IF PLAYER WON
				if (playerwon == true) {
					cout << "Play Again?" << endl;
					cin >> playAgain;
					if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
						cout << "Enter Y or N" << endl;
						continue;
					}
					else {
						playerwon = false; 
						break;
					}
				}
				else {
					break;
				}
			}
			if (playAgain == 'y' || playAgain == 'Y') { //START NEW GAME
				player1pot = 0;
				player1score = 0;
				AIpot = 0;
				AIRoll = 0;
				AIscore = 0;
				playAgain = 't';
				cout << "NEW GAME" << endl;
				cout << endl;
			}
			else if (playAgain == 'n' || playAgain == 'N') {
				break;
			}
			cout << endl;
			OutputScore(player1score, AIscore);
			cout << "AI Turn" << endl;
			while (true) {                               //AI turn
			    randRoll = (rand() % 6) + 1;
				cout << "Die Roll: " << randRoll << "   Pot: " << AIpot << endl;
				if (randRoll == 1) {
					AIpot = 0;
					AIRoll = 0;
					
					cout << "UH OH, Die Roll 1 - Player's turn " << endl;
					cout << endl;
					break;
				}
				AIpot += randRoll;
				AIRoll += randRoll;
				if (AIRoll >= 20) {
					
				    AIRoll = 0;
					AIscore += AIpot;
					cout << endl;
					break;
				}
				if (AIscore >= 50) {
					
					cout << "AI Won!!!" << endl;
					OutputScore(player1score, AIscore);
					playerwon = true;
					AIRoll = 0;
					cout << endl;
					break;
				}
				else {
					continue;
				}
			}
			while (true) {
				if (playerwon == true) {
					cout << "Play Again?" << endl;
					cin >> playAgain;
					if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
						cout << "Enter Y or N" << endl;
						continue;
					}
					else {
						playerwon = false;
						break;
					}
				}
				else {
					break;
				}
			}
			if (playAgain == 'y' || playAgain == 'Y') {
				player1pot = 0;
				player1score = 0;
				AIpot = 0;
				AIRoll = 0;
				AIscore = 0;
				playAgain = 't';
				cout << "New Game" << endl;
				cout << endl;
			}
			else if (playAgain == 'n' || playAgain == 'N') {
				break;
			}
		}
		if (playAgain == 'n' || playAgain == 'N') {
			break;
		}
	}
	cout << "Thanks for Playing!!!" << endl;
	return 0;
}