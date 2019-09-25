#include <iostream>
#include "Customer.h"
#include "Album.h"
#include "HashTable.h"

/** Constructor */
Customer::Customer() {
	firstName = "0";
	lastName = "";
	phoneNo = "";
	address = "";
	city = "";
	state = "";
	zip = "";
}

Customer::Customer(string f, string l, string p, string a, string c, string s, string z) {
	firstName = f;
	lastName = l;
	phoneNo = p;
	address = a;
	city = c;
	state = s;
	zip = z;

}

/** Manipulation Procedures */
void Customer::set_firstName(string f) {
	firstName = f;
}

void Customer::set_lastName(string l) {
	lastName = l;
}

void Customer::set_phone(string p) {
	phoneNo = p;
}

void Customer::set_address(string a) {
	address = a;
}

void Customer::set_city(string c) {
	city = c;
}

void Customer::set_state(string s) {
	state = s;
}

void Customer::set_zip(string z) {
	zip = z;
}

/** Access Functions */
string Customer::get_first() const {
	return firstName;
}

string Customer::get_last() const {
	return lastName;
}

string Customer::get_phone() const {
	return phoneNo;
}

string Customer::get_address() const {
	return address;
}
string Customer::get_city() const {
	return city;
}

string Customer::get_state() const {
	return state;
}

string Customer::get_zip() const {
	return zip;
}

void Customer::insertOrder(Order a) {

	o.insertStart(a);
}

//Order Customer::searchOrder(Order a) {
// add here
//}
/** Additional Functions */
ostream& operator<<(ostream& os, const Customer& c) {
	os << "First Name: " << c.get_first() << endl;
	os << "Last Name: " << c.get_last() << endl;
	os << "Phone #: " << c.get_phone() << endl;
	os <<"Address: " << c.get_address() << endl;
	os << "City: " << c.get_city() << endl;
	os << "State: " << c.get_state() << endl;
	os << "Zip: " << c.get_zip() << endl << endl;
	return os;
}

void Customer::displayOrd(ostream& os) {
	o.displayListNumberedList(os);
}

bool Customer::operator ==(const Customer& c) {
	return (firstName == c.get_first() && lastName == c.get_last());
}


Order Customer:: searchOrder(Order r)
{
int i=o.linearSearch(r);
if(i==-1) return r;
o.moveToIndex(i);
return o.getIterator();
}

