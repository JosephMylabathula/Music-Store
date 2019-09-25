
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include "List.h"
#include "Customer.h"

using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable(){}
    //constructor

    ~HashTable(){}
    //destructor


    /**Access Functions*/



    int search(string f,string g);

    int hash(string key) const;
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: firstName + lastName


    /** Manipulation Functions */

    void insert(Customer c);
    //inserts customer to the hashtable (using hashing algorithm to get index)


    /**Additional Functions*/

    void printCustomer(ostream& out) const;
    //prints Customer info index by index
    //in unsorted manner

    Customer searchcus(string fname,string lname);
    //searches for customer
    //returns data type customer

private:
    static const int SIZE = 75;
    List<Customer> Table[SIZE];

};



#endif /* HASHTABLE_H_ */
