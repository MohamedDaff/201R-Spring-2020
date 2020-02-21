//Cristofer James
//CS201R
//Program 2
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void menu_display();
int get_value(string message_to_prompt);
double get_value(int wall_num, double& wall_parameter, string to_prompt);
double house_area(double length, double height);
void input_validation(int& user_input_int);
void input_validation(double& user_input_int);
int cans_required(double wall_area, const double coverage);
double paint_cost(int num_cans, const double paint_can_cost);

int main()
{
	const double EXT_PAINT_CAN_COST = 150.00;
	const double INT_PAINT_CAN_COST = 100.00;
	const double PAINT_CAN_COVERAGE = 400.00;

	int option_choice;
	int num_walls;
	int num_int_cans = 0;
	int num_ext_cans = 0;
	int total_num_cans = 0;

	double length = 0.0;
	double height = 0.0;
	double total_interior_wall_area = 0.0;
	double total_exterior_wall_area = 0.0;
	double total_int_cost = 0.0;
	double total_ext_cost = 0.0;

	string get_choice_prompt = "\nWhich option would you like? ";
	string get_wall_num_prompt = "\n\tHow many walls will be painted? ";
	string get_wall_length_prompt = "\t\tEnter the length: ";
	string get_wall_height_prompt = "\t\tEnter the height: ";

	cout << fixed << setprecision(2) << endl;
	menu_display();
	option_choice = get_value(get_choice_prompt);
	
	switch (option_choice)
	{//Handles the option the user chooses and calls appropriate functions for the task
	case 1:
	{//Handles selection 1 for interior painting
		num_walls = get_value(get_wall_num_prompt);

		for (int w = 1; w <= num_walls; w++)
		{
			cout << "\n\t[Dimensions for wall " << w << "]" << endl;
			get_value(w, length, get_wall_length_prompt);
			get_value(w, height, get_wall_height_prompt);

			total_interior_wall_area += house_area(length, height);
		}

		cout << "\nTotal interior wall area to be painted: " << total_interior_wall_area
			 << " square feet." << endl;
		
		num_int_cans = cans_required(total_interior_wall_area, PAINT_CAN_COVERAGE);
		cout << "\nNumber of cans required to paint the interior walls: "
			 << num_int_cans << endl;

		total_int_cost = paint_cost(num_int_cans, INT_PAINT_CAN_COST);
		cout << "\nThe total price to paint the interior walls is : $"
			<< total_int_cost << endl;

		break;
	}
	case 2:
	{//Handles selection 2 for exterior painting
		num_walls = get_value(get_wall_num_prompt);

		for (int w = 1; w <= num_walls; w++)
		{
			cout << "\n\t[Dimensions for wall " << w << "]" << endl;
			get_value(w, length, get_wall_length_prompt);
			get_value(w, height, get_wall_height_prompt);

			total_exterior_wall_area += house_area(length, height);
		}

		cout << "\nTotal exterior wall area to be painted: " << total_exterior_wall_area 
			 << " square feet." << endl;

		num_ext_cans = cans_required(total_exterior_wall_area, PAINT_CAN_COVERAGE);
		cout << "\nNumber of cans required to paint the exterior walls: "
			<< num_ext_cans << endl;

		total_ext_cost = paint_cost(num_ext_cans, EXT_PAINT_CAN_COST);
		cout << "\nThe total price to paint the exterior walls is : $"
			<< total_ext_cost << endl;

		break;
	}
	case 3:
	{//Handles selection 3 for both exterior and interior painting
		num_walls = get_value(get_wall_num_prompt);

		for (int w = 1; w <= num_walls; w++)
		{
			cout << "\n\t[Dimensions for wall " << w << "]" << endl;
			get_value(w, length, get_wall_length_prompt);
			get_value(w, height, get_wall_height_prompt);

			total_interior_wall_area += house_area(length, height);
		}

		total_exterior_wall_area = total_interior_wall_area;

		cout << "\nTotal exterior and interior wall area to be painted: "
			<< total_interior_wall_area + total_exterior_wall_area << " square feet." << endl;
		//Assigns interior variables with the function calls
		num_int_cans = cans_required(total_interior_wall_area, PAINT_CAN_COVERAGE);
		total_int_cost = paint_cost(num_int_cans, INT_PAINT_CAN_COST);

		//Assigns interior variables with the function calls
		num_ext_cans = cans_required(total_exterior_wall_area, PAINT_CAN_COVERAGE);
		total_ext_cost += paint_cost(num_ext_cans, EXT_PAINT_CAN_COST);

		total_num_cans = num_int_cans + num_ext_cans;

		cout << "\nNumber of cans required to paint the interior and exterior walls: "
			 << total_num_cans << endl;
		cout << "\nThe total price to paint both the interior and exterior walls is : $"
			 << total_int_cost + total_ext_cost << endl;
		break;
	}
	default:
	{//In the event the program somehow bypasses the rest of the cases, it will display an error 
	 //message and break from the switch to exit
		cout << "\n\nAn error was encountered. The program will now exit." << endl << endl;
		break;
	}
	}

	system("pause");
	return 0;
}

void menu_display()
{//Displays the main menu to the user
	cout << "Welcome to the paint shop" << endl << endl;
	cout << "We have a couple of options that you can choose from:" << endl;
	cout << "1) Paint the interior of the house" << endl;
	cout << "2) Paint the exterior of the house" << endl;
	cout << "3) Paint both interior and exterior of the house" << endl;
}

int get_value(string message_to_prompt)
{//Gets the value for the menu option
	int to_return;
	cout << message_to_prompt;
	cin >> to_return;
	input_validation(to_return);

	return to_return;
}

double get_value(int wall_num, double& wall_parameter, string to_prompt)
{//Gets the value for the length or width of a wall
	double paramater = wall_parameter;

	cout << to_prompt;
	cin >> wall_parameter;
	input_validation(wall_parameter);

	return wall_parameter;
}

double house_area(const double length, const double height)
{//Calculates and returns house area when passed the length and width
	double area = 0;
	area = height * length;

	return area;
}

void input_validation(int& user_input_int)
{//Validates integer inputs
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nInvalid Entry. Try Again." << endl;
		cin >> user_input_int;
	}
}

void input_validation(double& user_input_int)
{//Validates double inputs
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nInvalid Entry. Try Again." << endl;
		cin >> user_input_int;
	}
}

int cans_required(double wall_area, const double coverage)
{//Calculates and returns the number of paint cans required given wall area and paint can coverage
	int cans = 0;
	cans = static_cast<int>(ceil(wall_area / coverage));

	return cans;
}

double paint_cost(int num_cans, const double paint_can_cost)
{//Takes the number of cans and cost of the can to get the total cost for the paint requried
	double cost = 0;
	cost = static_cast<double>(num_cans) * paint_can_cost;

	return cost;
}