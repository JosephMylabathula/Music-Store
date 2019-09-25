#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <string>
#include "List.h"
#include "Order.h"

using namespace std;

class Customer {
private:
	string firstName;
	string lastName;
	string phoneNo;
	string address;
	string city;
	string state;
	string zip;
	List<Order> o;

public:
	/** Constructor**/
	Customer();
	Customer(string f, string l, string p, string a, string c, string s, string z);

	/** Manipulation Procedures */

	void set_firstName(string f);
	//sets customer's first name

	void set_lastName(string l);
	//sets customer's last name

	void set_phone(string p);
	//sets customer's phone number

	void set_address(string a);
	//sets customer's address

	void set_city(string c);
	//sets customer's city

	void set_state(string s);
	//sets customer's state

	void set_zip(string z);
	//sets customer's zip

	void insertOrder(Order b);
	//adds order to customer

	/**Access Functions**/

	string get_first() const;
	//returns customer's first name

	string get_last() const;
	//returns customer's last name

	string get_phone() const;
	//returns customer's phone no.

	string get_address() const;
	//returns customer's address

	string get_city() const;
	//returns customer's city

	Order searchOrder(Order r);

	string get_state() const;
	//returns customer's address state

	string get_zip() const;
	//returns customer's zip

	/** Additional Functions */
	friend ostream& operator<<(ostream& os, const Customer& c);
	//prints out a customer to the designated stream in the following format
	//<lastName>, <firstName>
	//<phoneNo>
	//<address>
	//<city>
	//<state>
	//<zip>

	bool operator==(const Customer& c);
	//checks whether two customers are the same


	void displayOrd(ostream& os);
	//displays what the customer has ordered

};

#endif /* CUSTOMER_H_ */
