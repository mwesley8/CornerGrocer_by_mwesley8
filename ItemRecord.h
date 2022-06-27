#ifndef ITEMRECORD_H                                 // Preprocessor directives
#define ITEMRECORD_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

class ItemRecord                                       // Class Declaration
{
private:                                               // Access specifier
	string m_Item{ "none" };                           // Declare/initialize member variables
	int m_Frequency{ 0 };
public:
	vector<ItemRecord> records;                        // Declare vector of object type class

	ItemRecord(string t_item, int t_frequency);        // Custom constructor declaration
	ItemRecord();                                      // Default constructor declaration

	void SetItem(string t_item);                       // Mutator function declaration for member variables
	void SetFrequency(int t_frequency);
	
	string GetItem() const;                            // Accessor function declaration for member variables
	int GetFrequency() const;
	
	void PrintRecord() const;                          // Print object instance member variables
};
#endif
