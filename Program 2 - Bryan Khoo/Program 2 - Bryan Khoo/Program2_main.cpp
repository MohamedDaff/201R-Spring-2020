#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
//declare all the functions 
int MainMenu();
int CalculateArea();
void CalculateTotalCost(int area, int price, string typeOfWall);
void CalculateBothArea();

int main() {
	//declare necessary variables
	int userAns, area;
	userAns = MainMenu();
	//switch statement to call different functions
	switch (userAns) {
	case 1: area = CalculateArea(); CalculateTotalCost(area, 100, "interior"); break;
	case 2: area = CalculateArea(); CalculateTotalCost(area, 150, "exterior"); break;
	case 3: CalculateBothArea(); break;
	}

	return 0; 
}
//function for printint out the menu
int MainMenu() {
	int ans;
	cout << "Welcome to paint shop" << endl;
	cout << "We have couple of options that you can choose from:" << endl;
	cout << "1 - Paint the interior of a house" << endl;
	cout << "2 - Paint the exterior of a house" << endl;
	cout << "3 - Paint both interior and exterior of a house" << endl;
	cout << "What option fits you more ?" << endl;
	//loop to ask user for input, if user does not enter valid input, prompt for input again
	do {
		cin >> ans;
		if (ans < 1 || ans > 3)
			cout << "Invalid input. Please enter 1, 2 or 3." << endl;
	} while (ans < 1 || ans > 3);
	cout << endl;
	return ans;
}
//function for calculating area 
int CalculateArea() {
	//declaring all needed variables
	int numOfWalls, height, length, area, i;
	//print out question and prompt user input
	cout << "Now, how many walls do you want to paint" << endl;
	cin >> numOfWalls; 
	//create vector to store all the wall height and wall length
	vector<int> wallHeight(numOfWalls);
	vector<int> wallLength(numOfWalls);
	//loop to keep asking for input and store them into the respective vectors
	for (i = 0; i < numOfWalls; i++) {
		cout << "What is the length and hight for wall " << i + 1 << endl;
		cout << "Length = ";
		cin >> length;
		cout << "\nHeight = ";
		cin >> height;
		wallLength.at(i) = length;
		wallHeight.at(i) = height;
	}
	area = 0;
	//calculate total area
	for (i = 0; i < numOfWalls; i++) {
		area += (wallLength.at(i) * wallHeight.at(i));
	}
	return area;
}
//function for calculating the total cost to paint the walls
void CalculateTotalCost(int area, int price, string typeOfWall) {
	//declare and initialize the cans to area ratio. Declare total cans in double and integer
	double cansToArea = 400, totalCans;
	int totalCansWholeNum;
	//get the total cans in decimal
	totalCans = area / cansToArea;
	//round up the total cans to get whole number
	totalCansWholeNum = ceil(totalCans);
	//print out information for user
	cout << "As each can covers 400 feet" << endl;
	cout << "With area = " << area << " square feet, you will need to get " << totalCans << endl;
	cout << "So in total we need " << totalCansWholeNum << " cans" << endl;
	cout << "Now lets calculate the cost to paint the " << typeOfWall << " of the house" << endl;
	cout << "The price of the can is $ " << price << endl;
	cout << "The total cost is $ " << totalCansWholeNum * price << endl;
}
//function for calculating interior and exterior walls
void CalculateBothArea() {
	//declare all necessary variables
	int totalArea, totalCans, totalPrice;
	double areaInterior, areaExterior, totalCansInterior, totalCansExterior;
	//have an array to store prices for exterior walls and interior walls
	int price[2] = { 100, 150 };
	string typeOfArea[2] = { "interior", "exterior" };
	//get interior walls area
	cout << "INTERIOR" << endl;
	areaInterior = CalculateArea();
	cout << endl;
	//get exterior walls area
	cout << "EXTERIOR" << endl;
	areaExterior = CalculateArea();
	//calculate cans needed for interior and exterior seperately
	totalCansInterior = areaInterior / 400;
	totalCansExterior = areaExterior / 400;
	totalCans = ceil(totalCansInterior + totalCansExterior);
	//print all information needed to user
	cout << "As each can covers 400 feet" << endl;
	cout << "The interior area = " << areaInterior << " square feet, you will need " << totalCansInterior << endl;
	cout << "The exterior area = " << areaExterior << " square feet, you will need " << totalCansExterior << endl;
	cout << "So in total we need " << totalCans << " cans" << endl;
	//print price of can for interior and exterior seperately 
	for (int i = 0; i < 2; i++) {
		cout << "Now lets calculate the cost to paint the " << typeOfArea[i] << " of the house\nThe price of the can for "<< typeOfArea[i] <<" is $ " << price[i] << endl;
	}
	totalCansInterior = ceil(totalCansInterior);
	totalCansExterior = ceil(totalCansExterior);
	//since price differs for interior and exterior, calculate them seperately
	totalPrice = (totalCansInterior * 100) + (totalCansExterior * 150);
	//give user total cost
	cout << "The total cost is $ " << totalPrice << endl;
}