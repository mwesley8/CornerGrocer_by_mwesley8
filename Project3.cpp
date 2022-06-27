#include <iostream>
#include "Project3.h"
#include "CallPython.h"
#include "Windows.h"
#include "Python.h"
#include "ItemRecord.h"
#include <string>
#include <cctype>
#include <iomanip>
#include <regex>


using namespace std;

void RunProgram::printMenu() {
	// Method defintion to output menu to user
	cout << setw(66) << right << "CORNER GROCER MENU" << endl;
	cout << setw(27) << " " << string(60, '*') << endl;
	cout << "" << endl;
	cout << setw(27) << " " << "** 1: Print list of items and frequency purchased in a day * " << endl;
	cout << "" << endl;
	cout << setw(27) << " " << string(60, '*') << endl;
	cout << "" << endl;
	cout << setw(27) << " " << "** 2: Number of an item that was purchased in a day        *" << endl;
	cout << "" << endl;
	cout << setw(27) << " " << string(60, '*') << endl;
	cout << "" << endl;
	cout << setw(27) << " " << "** 3: Create graph of items purchased & frequency of each  *" << endl;
	cout << "" << endl;
	cout << setw(27) << " " << string(60, '*') << endl;
	cout << "" << endl;
	cout << setw(27) << " " << "** 4: Exit                                                 *" << endl;
	cout << "" << endl;
	cout << setw(27) << " " << string(60, '*') << endl;
}
string getItem() {
	// Method definition to get user input for an item
	system("cls");
	string userItem;
	regex item("[a-zA-Z' ']+");
	// Loop to validate user input
	while (true) {
		cout << "\nPlease enter the item: \n" << endl;
		getline(cin, userItem, '\n');
		// Check user input contains only upper/lower case characters
		if (regex_match(userItem, item)) {
			break;
		}
		else {
		// User input does not only contain upper/lower case characters
			system("color 46");
			cout << "\nYou have entered an invalid search item.\n" << endl;
			cout << "Please enter a valid item.\n" << endl;
			system("pause");
			cin.clear();
			system("cls");
			system("color 1C");
		}

	}
	return userItem; // return userInput
}
int RunProgram::checkNum() {
	// Function to check user selection
	string userInput{};                                     // Declare/initialize local variables
	int userNum{};
	printf("\n\n\n");
	// Loop to check user input
	while (true) {
		printMenu();                                        // Function call to print menu
		printf("\n\n");
		cout << "Please enter your selection:" << endl;     // Output to user
		regex selection("[1-4]");                           // Regex classification
		getline(cin, userInput, '\n');                      // Get user input
		// Condition to check user input
		if (regex_match(userInput, selection)) {
			userNum = stoi(userInput);
			break;
		}
		// Condition when previous condition false
		else {
			// Output to user
			system("color 46");
			cout << "\nPlease enter a valid option. \n" << endl;
			system("pause");
			cin.clear();
			system("cls");
			system("color 1C");
		}
	}
	return userNum; // return user input
}
void RunProgram::itemPurchases(string t_product, int t_ItemPurchases) {
	// Function to output the item and frequency

	// Condtion and output when value is greater than zero
	if (t_ItemPurchases > 0) {
		cout << endl;
		cout << t_product << " were purchased " << t_ItemPurchases << " times.\n" << endl;
	}
	// Condition and output when value is zero
	else {
		cout << "\nItem was not found.\n" << endl;
	}
}
void RunProgram::createGraph() {
	// Function to output graph of items and frequencies

	auto record = make_shared<ItemRecord>();         // Declare/initialize local pointer and variables
	string line = "";
	ifstream file;
	// Open file
	file.open("frequency.dat");
	getline(file, line);                             // Get the first line of the file
	line = "";                                       // Reinitialize local variable
	
	if (file.is_open()) {                            // Check if file is open
		// Loop to read file
		while (getline(file, line)) {
			string item;                             // Declare/initialize local loop variables
			int frequency;
			string tempString;
			stringstream inputStream(line);

			getline(inputStream, item, ',');         // Read and assign local loop variables
			record->SetItem(item);                   // Set member variable oject instance value
			getline(inputStream, tempString);        // Read and assign local loop variables
			frequency = stoi(tempString);            // Convert string to integer
			record->SetFrequency(frequency);         // Set member variabe object instance value
			record->records.push_back(*record);      // Add object instance to vector
		}
	}
	// Close the file
	file.close();
	// Output to user
	cout << "** Histogram Item Purchase Frequency **" << endl;
	cout << string(39, '=') << endl;
	// Interate over vector with object instances
	for (auto info : record->records) {
		info.PrintRecord();                           // Output to user
	}
	cout << string(39, '=') << endl;
	cout << endl;
}
void RunProgram::runProgram() {
	// Function to run program
	int userInput{};                                  // Declare/initialize local variable for user input
	auto cp = make_shared<CallPython>();              // Declare/initialize local pointers
	auto run = make_shared<RunProgram>();
	// Loop to run program
	while (true) {
		system("cls");
		// Local variable for item
		string product;
		// Function call to validate and assign user input
		userInput = checkNum();
		// Switch cases based on user input
		switch (userInput)
		{
		case 1:
			system("cls");
			// Initialize python and call function to print item and frequency
			cp->callPython("PythonCode", "printList");
			system("pause");
			break;
		case 2:
			system("cls");
			// Assign local variable to value returned from function call
			product = getItem();
			// Initialize python and function call to print specific item frequency
			run->itemPurchases(product, cp->callIntFuncString("specificItem", product));
			system("pause");
			break;
		case 3:
			system("cls");
			// Initialize python and function call to write file
			cp->callPython("PythonCode", "writeFile");
			// Function call to C++ to output graph from file created
			run->createGraph();
			system("pause");
			break;
		default:
			system("cls");
			// Output to user upon program end
			printf("\nYou have decided to exit. \n\n");
			printf("Goodbye..\n\n");
			exit(0);
			break;
		}
	}
}
