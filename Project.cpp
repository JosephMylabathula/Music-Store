//============================================================================
// Name        : Project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Employee.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "Order.h"
#include "HashTable.h"
#include "Customer.h"
#include "Album.h"
#include "BST1.h"
#include "BST2.h"
#include "Product.h"
#include <vector>

int Question()
{
    int question;

    cout << "What would you like to do today?: " << endl;
    cout << "1. Search for Customer" << endl;
    cout << "2. Display unsorted customer information:" << endl;
    cout << "3. View Orders by priority:" << endl;
    cout << "4. Ship an Order" << endl;
    cout << "5. List database of product: "<<endl;
    cout << "6. Add a Product" << endl;
    cout << "7. Remove Product" << endl;
    cout << "8. Exit" << endl;
    cout << "Please enter a number: " << endl;
    cin >> question;
    cin.ignore();

    while (question > 8 || question < 1)
    {
        cout << "Error Input not valid, Enter again: ";
        cin >> question;
    }

    return question;
}

int Question2()
{

    int question2;

    cout << "What would you like to do today?: " << endl;
    cout << "1. Search for a product" << endl;
    cout << "2. List Database of Products" << endl;
    cout << "3. Place an Order" << endl;
    cout << "4. View Purchases" << endl;
    cout << "5. Quit" << endl;

    cin >> question2;
    cin.ignore();

    while (question2 > 5 || question2 < 1)
    {
        cout << "Error Input not valid, Enter again: ";
        cin >> question2;
        cin.ignore();
    }

    return question2;
}

int main()
{



    /** HASHTABLE STUF===========================================================*/
    //Loading Customer into hashtable
    //by reading in from a text file
    HashTable H; //storing customer here
    ifstream fin,ifs;
    string line,l;
    string first, last, phone, address, city, state, zip;
    ofstream fout,ofs;

    ifs.open("OriginalAlbums.txt");
    ofs.open("Albums.txt");
    while(getline(ifs,l))
    	ofs << l << endl;
    ifs.close();
    ofs.close();

    fout.open("Orders.txt");
    if(fout.fail())
    {
    	cout << "Couldn't locate Orders file" << endl;
    }


    //to check whether opening txt file was successful
    fin.open("Customer.txt");
    if (fin.fail())
    {
        cout << "Couldn't locate file." << endl;
        //exit(1);
    }

    while (!fin.eof())
    {
        getline(fin, first);
        getline(fin, last);
        getline(fin, phone);
        getline(fin, address);
        getline(fin, city);
        getline(fin, state);
        getline(fin, zip);
        fin >> ws;
        Customer temp(first, last, phone, address, city, state, zip);
        H.insert(temp);
    }
//
//		//Testing printCustomer
//		cout << "Testing printCustomer Function: \n\n";
//		H.printCustomer(cout);
//
//		//Testing searchCustomer
//		cout << "Testing searchCustomer: \n\n";
//		cout << H.searchcus("Stephaine","Vinning");
    /** HASHTABLE END=================================================================*/



    //sample test for 2 and 3=========================
    Album album1;
    album1.set_title("Hello World");
    Order order1("11/22/96", 1, 2, 3);
    Order order2("2/23/91", 4, 4, 4);
    Customer c1("David","Copperfield","650-695-7334","Stevens Creek Blvd","Cupertino","CA", "95014");
   //order1.chooseProduct(album1);
   // order2.chooseProduct(album1);
    H.insert(c1); //david now in hashtable

    //=====================================================


    cout << "Helloooooooo" << endl;

    cout << "Welcome to main" << endl;
    cout << "!!!Welcome to our store!!!" << endl;

    string id, r, product;
    int response, re;
    Employee E;
    string CusEmp;

    Order y = Order("-1", -1, -1, -1);

    vector<Order> m;
    vector<Order> &h = m;

    m.push_back(y);

    PriorityQueue pq(h);
    c1.insertOrder(y);
    Order order;

    //PriorityQueue P;

    Product p;
    Album A;

    string album, genre;
    int year;
    double price;
int q=0;
    string artistName;
do{
    cout << "Are you customer or employee: ";
    cin >> CusEmp;
/*
	while (CusEmp != "employee" || CusEmp != "Employee" || CusEmp != "Customer"
			|| CusEmp != "customer") {
		cout << "Enter Again: Are you a Customer or Employee?" << endl;
		cin >> CusEmp;
		cin.ignore();
	}
*/
    if (CusEmp == "employee" || CusEmp == "Employee")
    {
        cout << "Enter your ID " << endl;
        cin >> id;
        while (id != "22C")
        {
            cout << "Invalid Employee ID" << endl;
            cout << "Enter Employee ID " << endl;
            cin >> id;
        }


        do
        {
            response = Question();

            switch (response)
            {

            case 1:
            {
                cout << "Enter the Last name of the customer you want to find: ";
                cin >> last;
                cout << "Enter the First name of the customer you want to find: " << endl;
                cin >> first;

                if (H.searchcus(first, last).get_phone() == " ")
                {
                    cout << "Customer not found " << endl;
                }
                else
                {
                    cout << H.searchcus(first, last);
                }

                break;
            }

            case 2:
            {
            	H.printCustomer(cout);
                break;
            }

            case 3:
            {

                cout << "view order by priority: \n";

                pq.displayArray(cout);
                break;

            }

            case 4:
            {

            	string f;

				Customer V;

				Album dummy;

				cout << "*****Change ship status*****"<< endl;

				string l;
				Customer v;
				cout << "Customer first name: ";

				cin >> f;
				cout << "Customer last name: ";
				cin >> l;
				v = H.searchcus(f, l);
				if (v.get_address() == " ")
					cout << "Customer not found" << endl;

				else {
					string c;
					int ordernum;
					cout << "Enter order Number" << endl;
					cin >> ordernum;
					Order dum("0", 0, ordernum, 0);
					dum = v.searchOrder(dum);

					if (dum.get_date() == "0")
						cout << " Invalid Order Number" << endl;
					else {
						dum.changeShipStatus("shipped");
						//pq.remove(1);
						pq.displayArray(cout);  //only for test  remove later
						dum.display(cout);  //for test remove later
					}

				}

                break;

            }

            case 5:
            {
                string AlbumOrArtist;

                cout << "By \n1. Album" << endl;

                cout << "2. Artist ?" << endl;

                cin >> AlbumOrArtist;

                while (AlbumOrArtist != "1" && AlbumOrArtist != "2")
                {
                    cout << "Please enter 1 or 2" << endl;
                    cin >> AlbumOrArtist;
                }

                if (AlbumOrArtist == "1")

                    p.printByTitle(cout);

                else if (AlbumOrArtist == "2")

                    p.printByArtist(cout);

                break;
            }

            case 6:
            {
                cout << "Enter Album you would like to add: " << endl;
                getline(cin, album);
                A.set_title(album);

                cout << "Enter the artist name: " << endl;
                getline(cin, artistName);
                A.set_artist(artistName);

                cout << "Enter the genre" << endl;
                getline(cin, genre);

                A.set_genre(genre);

                cout << "Enter the year: " << endl;
                cin >> year;

                A.set_year(year);

                cout << "Enter the price: " << endl;
                cin >> price;



                A.set_price(price);

                cout << "Displaying Album: " << endl;
                A.displayAlbum(cout);
                cout << endl;
                p.insertAlbum(A);

                break;
            }

            case 7:

            {

                Album dummy;

                cout << "Would you like to remove using 1. Album Title search or 2. Artist Search?" << endl;
                cout << "Please enter a number: " << endl;
                cin >> re;
                cin.ignore();

                while(re < 1 || re > 2)
                {
                	cout << "Error enter again " << endl;
                	cin >> re;
                	cin.ignore();
                }

                if(re == 1)
                {
                	cout << "What is the Album Title?: " << endl;

                	getline(cin,product);
                	cout << "Product: " << product << endl;
                	Album a=p.searchByTitle(product);
                	if(a.get_price() == 0.0){
                		cout << "Album not found." << endl;
                	}
                	else{
                		p.removeAlbum(a);
                		p. removeAlbum(a);
                		cout << "Album " << a.get_title() << " is removed." << endl;
                	}

                }
                else
                {
                	cout << "Who is the Artist?: " << endl;

                	getline(cin,product);
                	Album a=p.searchByArtist(product);
                	if(a.get_price() == 0.0){
                		cout << "Album not found." << endl;
                	}
                	else{
                		p.removeAlbum(a);
                		p.removeAlbum(a);
                		cout << "Album " << a.get_title() << " is removed" << endl;
                	}

                }


                break;
            }


            case 8:

            {

                cout << "Thank you! Bye!" << endl;
                q=2;

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
        while (response != 8);
    }



    else
    {

        int response2;

        Customer C;
        Album AB;

        do
        {

            response2 = Question2();
            string key, artist;

            switch(response2)
            {

            case 1:
            {

                cout<<"Do you want to search by 1. the name of the album or 2. name of the artist."<<endl;
                cin>>key;

//				while(key != "1" || key != "2")
//				{
//					cout<<"Please enter 1. to search by the name of the album or 2. to search by the artist's "
//					<< " name "<<endl;
//					cin>>key;
//				}

                if(key =="1")
                {
                    cout<<"Please enter name of the album: ";
                    //getline(cin, product);
                    cin>>product;
                    cin.ignore();
                    p.searchByTitle(product).displayAlbum(cout);

                }

                else if(key== "2")
                {
                    cout<<"Please enter the name of the artist: ";
                    getline(cin, artist);
                    cin.ignore();

                    p.searchByArtist(artist).displayAlbum(cout);
                }
                break;
            }

            case 2:
            {
                cout<<"Sorted by Album's name "<<endl;

                p.printByTitle(cout);

                cout<<"Sorted by artist's name "<<endl;

                p.printByArtist(cout);

                break;

            }

            case 3:
            {
            	 Order order;
                string cardinfo;
                int shipment=0;

                string shoppingDecision;


                Album dummy;

                    cout << "Enter the name of Album you would like to purchase"
                         << endl;

                    getline(cin, product);


                    dummy.set_title(product);

                    cout << "The name of the artist " << endl;
                    getline(cin, artistName);

                    dummy.set_artist(artistName);
                    Album C=p.searchByArtist(artistName);
                    if(C.get_price()==0.0)
                    {
                        cout<<"Album not found"<<endl;
                    }
                    else
                    {
                        Customer AA;

                        order.chooseProduct(C);
                        cout<<"Album "<< C.get_title()<<" by "  <<C.get_artist() <<" is added"<<endl;


                   // cout<<"Price without shipping price"<<endl;

                  //  order.totalCard();
//payment:
                order.viewCard(cout);
                cout<< endl << "Enter type of shipment, 1 for standard  2 for rush shipping , 3 for over night shipping "<<endl;
                cout<<" price for first: 1.99"<<endl;
                cout<<" price for first: 3.99"<<endl;
                cout<<" price for first: 5.99"<<endl;



                while(shipment <1 || shipment > 3)
                {
                    cout<<"Please enter 1, 2, or 3 "<<endl;
                    cin>>shipment;
                    cin.ignore();

                }

                order.set_typeOfShipment(shipment);

               // cout<< endl << "Final price: "<<endl;

               // cout<<order.Total();


                cout<< endl << "Please enter your credit card information: " << endl;;

                getline(cin, cardinfo);

                while ( !order.makePayment(cardinfo) )
                {
                    cout<< endl << "Please enter your credit card information again: ";

                    getline(cin, cardinfo);


                }




                    string address;

                             string city;

                             string state;

                             string zipCode;

                             string first, last;

                             string phone;

                             cout<<"Please enter your first name: ";
                             getline(cin, first);

                             AA.set_firstName(first);




                             cout<<"Please enter your last name: ";
                             getline(cin, last);



                             cout<<"Please enter your phone number: ";

                             getline(cin, phone);




                             cout<<"Please enter your address: ";

                             getline(cin,address);


                             cout<<"Please enter the city: ";

                             getline(cin, city);


                             cout<<"Please enter the state: ";

                             getline(cin, state);


                             cout<<"Please enter the zip code: ";
                             getline(cin, zipCode);

                             Customer customer(first, last, phone, address, city, state, zipCode);



                             order.set_orderNumber();


                                 order.display(cout);

                    Customer u=H.searchcus(first,last);
                    if(u.get_address()!=AA.get_address())
                    {


                        order.set_date();
                   order.setName(customer.get_first(),customer.get_last());
                   order.setCity(customer.get_city());
                   order.setShipAdress(customer.get_address());
                   order.setZip(customer.get_zip());
                   order.setState(customer.get_state());

                   pq.insert(order);
                   customer.insertOrder(order);
                   H.insert(customer);


                   cout<<"****ORDER information****"<<endl;
                   customer.displayOrd(cout);
                   customer.displayOrd(fout);
                    }

                    else{

                    order.set_date();
                    order.set_orderNumber();
                    order.setName(u.get_first(),u.get_last());
                    cout<< endl << "your order number is: "<<order.get_orderNumber()<<endl;
                   pq.insert(order);

                   u.insertOrder(order);
                   cout<<"****ORDER information****"<<endl;
                   u.displayOrd(cout);
                   u.displayOrd(fout);

                    }



                }
                break;
            }
            case 4:
            {
            	string first;
            	string last;
            	Customer AA;
                cout<<"Please enter your first name: ";
                                getline(cin, first);

                                AA.set_firstName(first);




                                cout<<"Please enter your last name: ";
                                getline(cin, last);

                                Customer u=H.searchcus(first,last);
                                if(u.get_address()==" ")
                                {
                                	cout<<"customer not found"<<endl;
                                }
                                else
                                {
                                	u.displayOrd(cout);

                                }
break;
            }

            case 5:
            {
            	cout << "Thank you for shopping with us today! Have a Great day!" << endl;
            	q=1;
            }
            }
        }while(response2!=5);

      }
 				// Print Orders to a file
    fin.close();
	fout.close();
}while(q==2 ||q==1);
}
