#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int area()
{
	int num_wall;
	int height;
	int length;
	int total;
	int sum_area=0.0;
	cout << "How many wall do you want to paint? ==> ";
	cin >> num_wall;
	cout << endl;
	for (int i = 1; i <= num_wall; ++i)
	{
		total = 0;
		cout << "What is the length and height of wall " << i << ":" << endl;
		
		cout << "Length =   " ;
		cin >> length;
		cout << "Height =   " ;
		cin >> height;
		cout << endl;
		total = length * height;
		sum_area = sum_area + total;
	}
	return sum_area;
}

float num_can(float area_cover)
{
	float count = area_cover / 400;
	return count;
}

float calculate_expense(float can, int price_per_can)
{
	int price = ceil(can) * price_per_can;
	return price;
}
void bill(string character, float are, float can, float price, int each)
{
	cout << "As each can cover 400 feets" << endl;
	cout << "With area = " << are << " square feets, you will get " << can << " can." << endl;
	cout << "So in total we need " << ceil(can) << endl;
	cout << "Now let calculate the cost to paint " << character << " of the house." << endl;
	cout << "The price of the can is $" << each << endl;
	cout << "The total cost is " << price << endl;
}
void menu()
{
	cout << "Welcome to paint shop" << endl;
	cout << "We have couple of options that you can choose from:" << endl;
	cout << "1 - Paint the interior of the house \n" << "2 - paint the exterior of the house \n" << "3 - paint both interior and exterior of the house" << endl;
}


int main() {
	float a;
	float aa;
	float b;
	float bb;
	float c;
	float cc;
	int price_can_i =100;
	int price_can_e =150;
	int user_choice;
	menu();
	while (true) {
		cout << "What option fit you more ? ";
		cin >> user_choice;
		if (user_choice == 1)
		{
			a = area();

			b = num_can(a);
			c = calculate_expense(b, price_can_i);
			bill("interior", a, b, c, price_can_i);
			break;
		}
		else if (user_choice == 2)
		{
			a = area();
			b = num_can(a);
			c = calculate_expense(b, price_can_e);
			bill("exterior", a, b, c, price_can_e);
			break;
		}
		else if (user_choice == 3)
		{
			cout << endl;
			cout << "For interior of the house" << endl;
			cout << endl;
			a = area();
			b = num_can(a);
			c = calculate_expense(b, price_can_i);
			cout << "For exterior of the house" << endl;
			cout << endl;
			aa = area();
			bb = num_can(aa);
			cc = calculate_expense(bb, price_can_e);
			bill("interior", a, b, c, price_can_i);
			cout << endl;
			bill("exterior", aa, bb, cc, price_can_e);
			cout << endl;
			cout << "The total is $" << c + cc << endl;
			break;
		}
		else
		{
			cout << "Please enter a valid choice." << endl;
			cout << endl;
			continue;
		}
	}
	system("pause");
	return 0;
}