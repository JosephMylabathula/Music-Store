#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "List.h"
#include "Album.h"

#include <ctime>

class Order {

protected:
	static int uniqueID;

private:

	string date;

	int PriroityShiping;  // ruh,over night shipping,...
	bool flag; //for display()
	int orderNumber;  //unique order number
	double totalorder; //total price, shipping is included
	double totalcardd;  //total price(shipping is not included
	double shipPrice;  //shipping price
	string shippingStatus; //shipping status, pending,shipped,...(default=pending)
	string comparedates;  // change local date and time to comparable string
	List<Album> b;  //list of product
	string fname;   //customer first name
	string lname;   //customer last name
	string shipadress;
	string zipcode;
	string state;
	string city;
	string shipmethod;

public:
	/** Constructor */

	Order(string a, int b, int c, int t);
	Order();
	Order(const Order& o);

	~ Order();

	/** Manipulation */

	void set_date(string d);
	//sets the date

	// void viewCard();
	//display shopping card before making a payment

	void set_typeOfShipment(int sh);
	//sets type of shipment,over night, rush,...

	bool remove(Album p);

	void shipMethod();

	void get_typeOfShipment(int sh);
	//returns type of shipment,over night, rush,...


	void chooseProduct(Album k);
	//customer choose product

	void changeShipStatus(string c);
	//change shipping status pending,shipped,...

	bool makePayment(string c);
	//enter credit card info, return true if card is valid

	void set_orderNumber();
	//sets a unique order number

	int get_orderNumber();
	// return the order number

	void dd(string c);
	void setCity(string s);

	void viewCard(ostream &out);

	void set_shipPrice();
	//sets shipping prices

	string get_date() const;
	//returns the date that order is made

	void set_date();
	//sets the date that order is made

	void setZip(string i);
	void setShipAdress(string m);
	void setState(string a);
	string getZip();
	string getShipAdress();
	string getState();
	 string getCity();

	void setName(string a, string b);
	//set customer first name and last name for queue

	string getFname();
	//return customet firstname

	string getLname();
	//return customer last name




	bool ordermpty();
	void displayShippingStatus();
	//displays shipping status,pending shipped,...

	void display(ostream &out);
	//display order info, before payment and after payment.

	double totalCard();
	//return total price(shipping price is not included)

	double Total();

	//return total price, shipping price is included)

	void confirmation();
	//displays confirmation

	void searchForOrder(int ordernumber);
	//searches for the order base on order number

	int get_priorityShipping();
	//return priority shipping, rush order=3,over night 2,...

	string getshipMethod();
	string compareDate(); //make comparable string date and return it

	friend ostream& operator<<(ostream& out, Order& Order);
	// bool operator=(Order a,Order b);

	bool operator==(Order a);
};

#endif // ORDER_H_INCLUDED
