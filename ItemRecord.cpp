#include "ItemRecord.h"

ItemRecord::ItemRecord(string t_item, int t_frequency) {            // Custom constructor definition
	SetItem(t_item);                                                // Mutate object instance member variables
	SetFrequency(t_frequency);                                      
}
ItemRecord::ItemRecord() {}                                         // Default constructor definition

void ItemRecord::SetItem(string t_item) {                           // Mutator member function definitions
	this->m_Item = t_item;
}

void ItemRecord::SetFrequency(int t_frequency) {
	this->m_Frequency = t_frequency;
}

string ItemRecord::GetItem() const {                                // Accessor member function definitions
	return this->m_Item;
}

int ItemRecord::GetFrequency() const {
	return this->m_Frequency;
}
// Output member variable object instances
void ItemRecord::PrintRecord() const {
	cout << string(13, ' ') << string(m_Frequency, '&') << endl;
	cout << m_Item << string(13 - m_Item.length(), '-') << string(m_Frequency, '&') << " " << m_Frequency << endl;
	cout << string(13, ' ') << string(m_Frequency, '&') << endl;
}
