#ifndef PROJECT3.H
#include "Windows.h"
#include "Python.h"
#include <string>
#include <iostream>

using namespace std;
// Class declaration
class RunProgram {
public:
	// Class member function declarations
	void printMenu();
	int checkNum();
	void runProgram();
	void itemPurchases(string t_product, int t_ItemPurchases);
	void createGraph();
};


#endif
