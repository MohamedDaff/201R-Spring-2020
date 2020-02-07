//Cristofer James
//CS201R Spring 2020
//Program 1

#include <iostream>
#include <ctime>

using namespace std;

void game_loop();
void intro_display();
int die_roll(int&);
void input_val(char);
void pot_control(int&, int);
void winner(int p_score, int ai_score);
void play_again();
bool bust(int);

//Global variable to determine if it's the human player's turn or not
bool is_plr_turn = true;

int main()
{
	//Prepare srand() using time(0) as a seed to generate random numbers
	srand(time(0));
	
	game_loop();

	return 0;
}

void game_loop()
{//Runs the game loop and calls other functions
	int pot_total = 0;
	int plr_score = 0;
	int ai_score = 0;
	char choice;

	intro_display();

	do {

		if (is_plr_turn == true)
		{
			int die_val = die_roll(pot_total);

			
			cout << "\n\n\tPlayer rolled: " << die_val;
			cout << "\tPot: " << pot_total << endl << endl;

			if (bust(die_val))
			{
				cout << "\n\t\tBUST!" << endl;
				cout << "\n\n===AI turn===" << endl;
				cout << "\n\tPlayer Score: " << plr_score << "\tAI Score: " << ai_score << endl << endl;
				system("pause");
				continue;
			}
			else
			{
				cout << "\tRoll again[R] or Hold[H]: ";
				cin >> choice;
			}

			input_val(choice);

			if (toupper(choice) == 'H')
			{
				plr_score += pot_total;
				pot_total = 0;
				is_plr_turn = false;

				cout << "\n\n===AI turn===" << endl;
				cout << "\n\tPlayer Score: " << plr_score << "\tAI Score: " << ai_score << endl << endl;
				system("pause");
			}
		
		}
		else
		{
			int die_val = die_roll(pot_total);

			cout << "\n\n\tAI rolled: " << die_roll(pot_total);
			cout << "\tPot: " << pot_total << endl << endl;

			if (bust(die_val))
			{
				cout << "\n\t\tBUST!" << endl;
				cout << "\n\n===Plyaer turn===" << endl;
				cout << "\n\tPlayer Score: " << plr_score << "\tAI Score: " << ai_score << endl << endl;
				system("pause");
				continue;
			}

			if (pot_total < 20)
				continue;
			else
			{
				ai_score += pot_total;
				pot_total = 0;
				is_plr_turn = true;

				cout << "\n\n===Player turn===" << endl;
				cout << "\n\tPlayer Score: " << plr_score << "\tAI Score: " << ai_score << endl << endl;
				system("pause");
			}
		}

	} while (plr_score < 50 && ai_score < 50);

	winner(plr_score, ai_score);
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

int die_roll(int& pot)
{//Generates a die roll

	//rand() % 6 generates values from 0 to 5 so by adding 1 to the result, it can generate values 1 to 6 for the dice
	int die = rand() % 6 + 1;
	
	pot_control(pot, die);

	return die;
}

void input_val(char ch)
{//Validates the user input and requests new input if the user input is invalid
	while (toupper(ch) != 'R' && toupper(ch) != 'H')
	{
		cout << "\n\n\t\tINVALID ENTRY!" << endl << "\t\tPLEASE TRY AGAIN." << endl << endl;

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << "\tRoll again[R] or Hold[H]: ";
		cin >> ch;
	}
}

void pot_control(int& pot, int die)
{//Controls the pot sum and resets the pot 0 if 1 is rolled
	if (die > 1)
		pot += die;
	else
		pot = 0;
}

void winner(int p_score, int ai_score)
{//Checks which player reached a score of 50 and outputs the winner
	cout << "\n\nPlayer score: " << p_score << "\tAI score: " << ai_score << endl;

	if (p_score >= 50)
		cout << "\n\t\tPlayer wins!" << endl;
	else
		cout << "\n\t\tAI wins!" << endl;

	play_again();
}

void play_again()
{//Asks the user if they want to play again and calls game_loop() if they do
	char again;

	cout << "\n\n\tWould you like to play again[Y/N]: " << endl;
	cin >> again;

	switch (again)
	{
	case 'Y':
	case 'y':
	{
		is_plr_turn = false;
		game_loop();
		break;
	}
	case 'N':
	case 'n':
	{
		cout << "\n\tGoodbye" << endl;
		break;
	}
	default:
	{
		cout << "\nInvalid entry. The game will now exit." << endl;
		break;
	}
	}

}

bool bust(int die)
{//Forces a turn swap if the current player rolls a 1
	if ((die == 1) && (is_plr_turn == true))
	{
		is_plr_turn = false;
		return true;
	}
	else
		if ((die == 1) && (is_plr_turn == false))
		{
			is_plr_turn = true;
			return true;
		}
	
	return false;
}