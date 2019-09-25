#include "HashTable.h"
#include "Customer.h"
#include "List.h"
#include <assert.h>

using namespace std;

/**Access Functions*/

//Key for this table: firstName + lastName
int HashTable::hash(string key) const {
	int index, sum = 0;
	for (unsigned i = 0; i < key.length(); i++) {
		sum += (int) key[i];
	}
	index = sum % SIZE;
	return index;
}

Customer HashTable::searchcus(string f, string l) {
	string s = f + l;

	unsigned index = hash(s);
	Customer c(f, l, " ", " ", " ", " ", " ");
	if (Table[index].getLength() == 0)
		return c;

	int i;
	i = Table[index].linearSearch(c);
	if (i == -1)
		return c;
	Table[index].advanceToIndex(i);
	return Table[index].getIterator();

}

/** Manipulation Functions */

void HashTable::insert(Customer c) {

	//gets the index where the customer is stored
	int index = hash(c.get_first() + c.get_last());
	Table[index].insertStop(c);
}

/**Additional Functions*/

void HashTable::printCustomer(ostream& out) const {
	for (int index = 0; index < SIZE; index++) {
		if (!Table[index].isEmpty()) {
			out << "INDEX NO: " << index << endl;
			Table[index].displayList(out);
		}

	}
}

//displays all the customer's info in unsorted order
