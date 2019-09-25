/*
 * order.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: maryamr
 */


#include "Order.h"

#include <iostream>
#include "Customer.h"
#include "math.h"
#include "stddef.h"
#include "Album.h"

#include <assert.h>
using namespace std;


int Order::uniqueID = 0;
Order::Order(){
	 date="";
	PriroityShiping=0;
	 orderNumber=0;
	 totalorder=0;
	totalcardd=0;
	flag=0;
	shippingStatus="pending";
	shipPrice=0;
	fname="";
	lname="";
	shipmethod="";

}

Order::Order(string a,int b,int c,int t){
	 date=a;
	PriroityShiping=b;
	 orderNumber=c;
	 totalorder=t;
	    //shipadress=;
	   // fname;
	   // lname;
       //zipcode;
        //state;
        //city;
}





Order::Order(const Order& o)
{
	b = o.b;
	date = o.date;
	PriroityShiping = o.PriroityShiping;
	orderNumber = o.orderNumber;
	totalorder = o.totalorder;
	totalcardd = o.totalcardd;
	flag = o.flag;
	shipPrice = o.shipPrice;
	shippingStatus = o.shippingStatus;
	fname = o.fname;
	lname = o.lname;
	shipadress = o.shipadress;
	zipcode = o.zipcode;
	state = o.state;
	city = o.city;
	shipmethod = o.shipmethod;

}


string Order::get_date() const {
	return date;
}

 void Order::setZip(string i)
 {

zipcode=i;
 }
 void Order::setShipAdress(string m)
 {

     shipadress=m;
 }
 void Order::setState(string a)
 {

     state=a;
 }


void Order::set_typeOfShipment(int sh)
{

	PriroityShiping=sh;

}

int Order::get_priorityShipping()

{
	return PriroityShiping;
}
void Order::setCity(string s)
{
    city=s;
}

void Order::set_orderNumber( )
{
	orderNumber=++uniqueID;

}

void Order::setName(string a,string b)
{
    fname=a;
    lname=b;
}


string Order::getFname()
{
    return fname;
}


string Order::getLname()
{
    return lname;
}


void Order::chooseProduct(Album k)
{
	b.insertStop(k);
}




bool  Order::makePayment(string c)
{
if(c.length()!=12)
{
	cout<<"message";
	return false;
}
for(int i=0;i<c.length();i++)
{
if(int(c[i])<48 || int(c[i])>57)
{
	cout<<"message";
	return false;
}
}
flag=1;
return true;
}


void Order::dd(string c)
    {
        date=c;
    }



double Order::totalCard()
{
int sum=0;
b.startIterator();
for(int i=0;i<b.getLength();i++)
{

	sum+=b.getIterator().get_price();
	b.moveIterNext();

}
totalcardd=sum;

return totalcardd;

}




void  Order::changeShipStatus(string c)
{
	shippingStatus=c;
}

double Order::Total()
{

this->set_shipPrice();
totalorder=totalcardd+shipPrice;
return totalorder;

}


/*
void Order::remove(Album p)
{
    int i=b.linearSearch(p);
    b.moveToIndex(i);
    b.removeIterator();
}
*/

void Order::shipMethod()
{
    if(PriroityShiping==3)shipmethod="Rush shipping";
    if(PriroityShiping==2)shipmethod="overnight shipping";
    if(PriroityShiping==1)shipmethod="standard shipping";
}


string Order::getshipMethod(){

	return shipmethod;
}
void Order::viewCard(ostream &out)
{

    b.displayList(out);
	this->totalCard();
	if(flag==0)
	out<<"total price: "<<totalcardd<<endl;

	cout<<endl;
}

void Order::display(ostream &out){

	b.displayList(out);

	this->totalCard();

	out<<"total price: "<<totalcardd<<endl;


		this->Total();
		out<<"order time: "<<date<<endl;
		out<< "order number: "<<orderNumber<<endl;
           out<< "shipping: "<<shipPrice<<endl;
          shipMethod();
        out<<"shipping method: " << shipmethod<<endl;


		cout<<"total price: "<<totalorder<<endl;
		cout<<"shipping adress: "<< shipadress<<" "<< city <<" "<< state<<" "<< zipcode<<endl;
		cout<<"order status: "<<shippingStatus;


	cout<<endl;
}



ostream& operator<<(ostream& out,  Order& c){

	c.display(out);
	cout<<endl;
	return out;
}


void Order::set_shipPrice(){


	if(PriroityShiping==1)shipPrice=1.99;
	if(PriroityShiping==2)shipPrice=3.99;
	if(PriroityShiping==3)shipPrice=5.99;
}


bool Order::remove(Album p)
{

    int i=b.linearSearch(p);
    if(b.isEmpty()==false and i!=-1)
    {
    b.moveToIndex(i);
    b.removeIterator();
    return true;
    }

    if(b.isEmpty()==true) cout<< "your card is empty"<<endl;
    else if(i==-1) cout<<"there is no such an Album in your card"<<endl;
    return false;
}


bool Order:: ordermpty()
{
	return b.isEmpty();
}




string Order::getShipAdress()
{
	return shipadress;
}
string Order:: getCity()
{
	return city;
}
string Order::getZip()
{

	return zipcode;


}
string Order::getState()
{
	return state;
}

void Order::set_date()
{
	{
	  // Current date/time based on current system
	  time_t now = time(0);

	  // Convert now to tm struct for local timezone
	  tm* localtm = localtime(&now);
date=asctime(localtm);


	  }
	}


string Order::compareDate()
{

	string cdate=date;
	cdate.erase(0,4);
	string year=cdate;

	year.erase(0,16);
	year.erase(4);

	string month=cdate;
	string day=month.erase(6,21);

	day.erase(0,4);
	month.erase(3,6);
	string monthh="";
	if(month=="Jan")month="1";
	if(month=="Feb")month="2";
	if(month=="Mar")month="3";
	if(month=="Apr")month="4";
	if(month=="May")month="5";
	if(month=="Jun")month="6";
	if(month=="Jul")month="7";
	if(month=="Aug")month="8";
	if(month=="Sep")month="9";
	if(month=="Oct")month="10";
	if(month=="Nov")month="11";
	if(month=="Dec")month="12";



	string time=cdate;
	time.erase(0,7);

	time.erase(8,13);

	cdate=year+month+time;


return cdate;
}

int Order::get_orderNumber(){
		return orderNumber;
	}


Order::~Order(){

}


void Order::set_date(string s)
{
	date=s;
}
 bool Order:: operator==(Order a)
{

	return get_orderNumber() == a.get_orderNumber();
}
