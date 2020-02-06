#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//declare all functions
void outputScore(int aiScore, int playerScore);
int rollDice();
void bust();
int playerTurn(string username, int score);
int aiPlays(string player, int score);
char userChoice(int final_playerScore, string username, int final_aiScore);


int main() {
	//declare needed variables
	int aiScore, playerScore, tempScore, aiChoice, ans; 
	string player = "Player";
	string ai = "AI";
	//have a counter for ai and player turns 
	int counter = 2;
	do {
		aiScore = 0;
		playerScore = 0;
		do {
			outputScore(aiScore, playerScore);
			// if counter is even, player's turn
			if (counter % 2 == 0) {
				tempScore = playerTurn(player, playerScore);
				playerScore = tempScore;
			}
			// if counter is odd, ai's turn 
			else {
				tempScore = aiPlays(ai, aiScore);
				aiScore = tempScore;
			}

			cout << endl;
			counter++;

		} while (aiScore < 50 && playerScore < 50);
		//compare which score is highest
		if (playerScore > aiScore)
			ans = userChoice(playerScore, player, aiScore);
		else
			ans = userChoice(playerScore, ai, aiScore);
	} while (ans == 'y' || ans == 'Y');
	
	return 0;
}


// function for output score
void outputScore(int aiScore, int playerScore) {
	cout << "Score		You: " << playerScore << " AI: " << aiScore << endl;
	cout << endl;
}
// function for rolling a dice
int rollDice() {
	int dieValue;
	do {
		dieValue = rand() % 10;
	} while (dieValue == 0);
	return dieValue;
}
//function for displaying bust message
void bust() {
	cout << "Die Roll: BUST" << endl;
}

int playerTurn(string username, int score) {
	int dieValue, potValue, firstRound;
	potValue = 0;
	firstRound = 0;
	string userChoice = "r";
	cout << username << " Turn" << endl;
	do {
		// if user enters 'r', continue playing
		if (userChoice == "r" || userChoice == "R") {
			dieValue = rollDice();
			if (dieValue != 1) {
				potValue += dieValue;
				cout << "Die Roll: " << dieValue << "		Pot: " << potValue << "		(R)oll again or (H)old? ";
				cin >> userChoice;
				firstRound++;
			}
			else {
				//if dice value is 1 and it is the first round, roll dice again 
				if (firstRound == 0)
					continue;
				bust();
				// change pot value to 0 and change user choice to 'h' to quit the loop
				potValue = 0;
				userChoice = "h";
			}
		}
		else {
			// ask user for input
			cout << endl;
			cout << "You must enter R or H" << endl;
			cout << "		(R)oll again or (H)old? ";
			cin >> userChoice;
		}
	} while (userChoice != "H" && userChoice != "h");
	// add the score with pot value and return total score
	score += potValue;
	return score;
}

int aiPlays(string player, int score) {
	int dieValue, aiPotValue, choice, firstRound;
	aiPotValue = 0;
	firstRound = 0;
	srand(time(0));
	cout << player << " Turn" << endl;
	choice = 1;
	// if choice = 1, roll dice, else quit loop
	while (choice == 1) {
		if (choice == 1) {
			dieValue = rollDice();
			if (dieValue == 1) {
				if (firstRound == 0)
					continue;
				bust();
				aiPotValue = 0;
				choice = 0;
			}
			else {
				aiPotValue += dieValue;
				cout << "Die Roll: " << dieValue << "		Pot: " << aiPotValue << endl;
				firstRound += 1;
				//randomize the ai choice
				choice = (rand() % 10) % 2;
			}
		}
		else
			break;
	}
	// add score with pot value and return total value
	score += aiPotValue;
	return score;
}

char userChoice(int final_playerScore, string username, int final_aiScore) {
	char ansUser;
	cout << "Congratulations " << username << "! You won!!" << endl;
	cout << "Total score:		Player = " << final_playerScore << " AI = " << final_aiScore << endl;
	cout << "Do you wish to play again? Enter Y/y for yes or N/n for no: ";
	cin >> ansUser;
	//if user input is invalid, keep asking until a valid answer is provided 
	while (ansUser != 'Y' && ansUser != 'y' && ansUser != 'N' && ansUser != 'n') {
		cout << "Please enter Y/y for yes or N/n for no:";
		cin >> ansUser;
		cout << endl;
	}
	cout << endl;
	return ansUser;
}