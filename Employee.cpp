/*
 * Employee.cpp
 *
 *  Created on: Jun 11, 2018
 *      Author: Joseph Mylabathula
 */

#include "Employee.h"
//#include "HashTable.h"
//#include "Product.h"
//#include "PriorityQueue.h"
//#include "List.h"
//#include "Customer.h"
//#include "BST.h"
#include <iostream>
#include <iomanip>
#include <string>

Employee::Employee()
{
	id = "22C";
}

string Employee:: get_id()
{
	return id;
}

/*
int Question()
{
	int question;

	cout << "What would you like to do today?: " << endl;
	cout << "1. Search for Customer" << endl;
	cout << "2. View Orders Sorted" << endl;
	cout << "3. Ship an Order" << endl;
	cout << "4. View Albums" << endl;
	cout << "5. Add a Product" << endl;
	cout << "6. Remove Product" << endl;
	cout << "7. Exit" << endl;
	cout << "Please enter a number: " << endl;
	cin >> question;

	while(question > 7 || question < 1)
	{
		cout << "Error Input not valid, Enter again: ";
		cin >> question;
	}

	return question;
}

int main()
{
	string id, f, l, product, a, s, g, y;
	//HashTable H;
	//Album A;
	//PriorityQueue P;
	// BST1 B1;				// Sorted by Album
	// BST2 B2;				// Sorted by Artist

	int response;
	Employee E;

	cout << "Enter ID: ";
	getline(cin, id);

	while(id != E.get_id())
	{
		cout << "Invalid Employee ID" << endl;
		cout << "Enter Employee ID " << endl;
		getline(cin,id);
	}

	do
	{
		response = Question();

		switch(response)
		{
			case 1:	// Yeong Hash Table
			{
				cout << "Enter the Last name of the customer you want to find: ";
				cin >> l;
				cout << "Enter the First name of the customer you want to find: " << endl;
				cin >> f;

				cout << "Last name: " << l << endl << "First name : " << f << endl;;
				H.searchCustomer(last, first);
				break;
			}
			case 2:	// Maryam Priority Queue Orders
			{
				P.displayArray(cout);
				break;
			}

			case 3:
			{	// Maryam Priority Queue Orders

				/*
				 * Myla, Joey
					Continuum
					John Mayer
					Pop
					2006

					Graduation
					Kanye West
					Graduation
					Hip Hop
					2007

					Total price: $18.99
					Order time: 3 Days
					Order Status: Shipped

					The Order has been changed

				P.changeShipStatus(Shipping);			// NEED HELP HERE
				break;
			}

			case 4:
			{
				// Ramin BST Products

					cout << "By \n1. Album" << endl;
					cout << "2. Artist ?" << endl;
					cin >> a;
					while(a != 1 && a != 2)
					{
						cout << "Error Wrong input" << endl;
						cout << "By \n1. Album" << endl;
						cout << "2. Artist ?" << endl;
						cin >> a;
					}

					if(a ==1)
						B1.inOrderPrint(cout);

					else if(a==2)
						B2.inOrderPrint(cout);

					break;
				}


			case 5:
			{
				// Ramin BST products
				cout << "Enter Album you would like to Add: " << endl;
				cin >> product;
				cout << "Enter the artist name: " << endl;
				cin >> a;
				cout << "Enter the genre" << endl;
				cin >> g;
				cout << "Enter the year: " << endl;
				cout << "Enter the songs: " << endl;
				B.insert(n);
				break;
			}

			case 6:
			{
				// Ramin BST products
				cout << "Enter the Album you would like to remove" << endl;
				cin >> product;
				cout << "Album " << product << " is removed" << endl;
				B.remove(n);
				break;
			}

			case 7:
			{
				cout << "Thank you!" << endl;
				break;
			}

			default:
			{
				cout << "Invalid Input Enter again: " << endl;
				response = Question();
				break;
			}
		}
	}
	while(response != 8);

}
*/
