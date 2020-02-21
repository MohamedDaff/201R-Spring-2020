//Davith Lon

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void displayMenu(void);
int getArea(std::string wallType);
void finalDisplay(void);
std::string menuValidInput();
void finalDisplay(int passArea, std::string wallType);
void finalDisplay(int intArea, int exArea, std::string wallType1, std::string wallType2);

using namespace std;

int main(){

    bool programStatus = true;
    char userInput;
    string selection[1];
    string option1 = "Interior";
    string option2 = "Exterior";
    int intArea = 0;
    int exArea = 0;

    do{
        displayMenu();
        selection[0] = menuValidInput();
    
        if(selection[0] == "1"){
            intArea = getArea(option1);
            finalDisplay(intArea, option1);
        }
        else if(selection[0] == "2"){
            exArea = getArea(option2);
            finalDisplay(exArea, option2);
        }
        else if(selection[0] == "3"){
            intArea += getArea(option1);
            exArea += getArea(option2);
            finalDisplay(intArea, exArea, option1, option2);
        }
        else{
            cout << "You broke this. Please stop." << endl;
            return -1;
        }
        
        cout << "Would you like to calculate again? (Y/N) " << endl;
        cin >> userInput;
        
        userInput = toupper(userInput);
        
        while(userInput != 'Y' && userInput != 'N'){
            cout << "Sorry that wasn't a valid input. Please Try again." << endl;
            cin >> userInput;
            userInput = toupper(userInput);
        }
        
        if(userInput == 'N'){
            programStatus = false;
        }
        else{
            programStatus = true;
        }
        
    }while(programStatus == true);
    
    
    return 0;
}



void displayMenu(void){
    cout << "Welcome to the Paint Shop" << endl;
    cout << "We have a couple of options that you can choose from:" << endl;
    cout << "1- Paint the interior of a house" << endl;
    cout << "2- Paint the exterior of a house" << endl;
    cout << "3- Paint both interior and exterior of a house" << endl;
    cout << "Please enter your selection." << endl;

}

int getArea(string wallType){
    
    int numWalls = 0, wallLength = 0, wallHeight = 0, totalArea = 0, thisArea = 0;
    
    cout << "How many " << wallType << " walls do you want to paint?" << endl;
    cin >> numWalls;
    while(numWalls <= 0){
        cout << "Sorry that was an invaid input. Please try again." << endl << endl;
        cin >> numWalls;
    }
    
    for (int i = 0; i < numWalls; ++i){
        cout << "What is the Length and Height of the wall " << (i + 1) << endl;
        cout << "Length: ";
        cin >> wallLength;
        cout << "Height: ";
        cin >> wallHeight;
        thisArea = wallLength * wallHeight;
        totalArea += thisArea;
    }
    
    return totalArea;
    
}

std::string menuValidInput(){
    
    string thisSelection[1];
    
    cin >> thisSelection[0];
    
    while( thisSelection[0] != "1" && thisSelection[0] != "2" && thisSelection[0] != "3" ){
        cout << "Sorry that was an invaid input. Please try again." << endl << endl;
        displayMenu();
        cin >> thisSelection[0];
    }
    
    return thisSelection[0];
    
}

void finalDisplay(int passArea, string wallType){
    
    double thisCans = (passArea/400.00), totalCost;
    
    if(wallType == "Interior"){
        totalCost = ceil(thisCans) * 100;
    }
    else{
        totalCost = ceil(thisCans) * 150;
    }
    
    cout << "A can of paint can cover 400 square feet." << endl;
    cout << "With your total area = " << passArea << " square feet, you will need to get " << thisCans << " cans." << endl;
    cout << "So, you need to buy " << ceil(thisCans) << " can(s)." << endl;
    cout << "Now lets calculate the cost to paint the " << wallType << " of the house." << endl;
    cout << "The price of a can of paint is $100" << endl;
    cout << "The total cost is $" << totalCost << endl;
    
}

void finalDisplay(int intArea, int exArea, string wallType1, string wallType2){
    
    int totalArea = intArea + exArea;
    double exCans = ceil((exArea/400.00));
    double inCans = ceil((intArea/400.00));
    double totalCost = 0.00;
    
    if(wallType1 == "Interior"){
        totalCost += inCans * 100;
    }
    
    if(wallType2 == "Exterior"){
        totalCost += exCans * 150;
    }
    
    cout << "A can of paint can cover 400 square feet." << endl;
    cout << "Your total area = " << totalArea << " square feet" << endl;
    cout << "So, you need to buy " << ceil(inCans) << " can(s) of interior paint." << endl;
    cout << "And, you need to buy " << ceil(exCans) << " can(s) of exterior paint." << endl;
    cout << "Now lets calculate the cost to paint the " << wallType1 << " and " << wallType2 << " of the house." << endl;
    cout << "The price of a can of interior paint is $100 and $150 for a can of exterior paint" << endl;
    cout << "The total cost is $" << totalCost << endl;
    
}
