//Cristofer James
//CS201R Spring 2020
//Program 1

#include <iostream>
#include <ctime>

using namespace std;

void intro_display();
void game_manager(bool);
int turn(bool&);
void turn_change(bool&);
int die_roll();
void input_val(char, bool);

int main()
{
	//Prepare srand() using time(0) as a seed to generate random numbers
	srand(time(0));

	//variables for storing the pot and player scores
	int pot_total = 0;
	int plr_score = 0;
	int ai_score = 0;
	bool is_plr_turn = true;

	intro_display();

	cout << "pot_total = " << pot_total << endl;
	cout << "plr_score = " << plr_score << endl;

	return 0;
}

void intro_display()
{//Function to display an introduction to the game and explain the rules
	cout << "\n\t   ~~~Pig Dice Game~~~" << endl << endl;
	cout << "\t   ______Rules______" << endl << endl;
	cout << " (1) Each player takes a turn rolling the die." << endl;
	cout << " (2) Each roll adds the die amount to the pot." << endl;
	cout << " (3) The player has the option to 'roll' or 'hold'." << endl;
	cout << " (4) 'Roll' allows the player to roll the die again for a larger pot." << endl;
	cout << " (5) 'Hold' will add the pot to the player's score." << endl;
	cout << " (6) 'Hold' will also end the player's turn." << endl;
	cout << " (7) Rolling a 1 will reset the pot and end the player's turn." << endl;
	cout << " (8) The first player to reach or pass a score of 50 wins." << endl << endl << endl;
}

void game_manager(bool is_turn)
{
	if (is_turn == true)
		turn(is_turn);
}

int turn(bool &plr_turn)
{
	char choice;

	cout << "Roll again[R] or Hold[H]: ";
	cin >> choice;

	input_val(choice, plr_turn);

	if (toupper(choice) == 'R')
		die_roll();
	else
		turn_change();

	return 5;
}

void turn_change(bool &plr_turn)
{
	if (plr_turn == true)
		plr_turn = false;
	else
		plr_turn = true;
}

int die_roll()
{//Generates a die roll

	//rand() % 6 generates values from 0 to 5 so by adding 1 to the result, it can generate values 1 to 6 for the dice
	int die = rand() % 6 + 1;

	return die;
}

void input_val(char ch, bool plr_turn)
{
	if (!cin || toupper(ch) != 'R' || toupper(ch) != 'H')
	{
		cout << "\n\n\t\tINVALID ENTRY!" << endl << "\t  PLEASE TRY AGAIN." << endl << endl;
		turn(plr_turn);
	}
}

