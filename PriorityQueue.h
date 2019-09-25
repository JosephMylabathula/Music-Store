#ifndef PriorityQueue_H_INCLUDED

#define PriorityQueue_H_INCLUDED
#include <vector>
#include <iostream>

#include "Order.h"
using namespace std;

class  PriorityQueue
{
   private:
    int heap_size;
    vector<Order> *heap;

    /**Helper Functions*/

    void heapify(int i);
    //helper function to build_heap, remove, and sort
    //bubbles an element down to its proper location within the heap

    void heap_increase_key( int i, Order b);
    //helper function to insert (base on date)

public:
     PriorityQueue(vector<Order> &b);
    //assigns heap to point to v, an unordered array
    //calls build_heap to convert the unordered array into a valid max heap

    /**Manipulation Procedures*/

    void build_heap();
    //Takes an unordered vector and builds it into a heap

    void insert(Order b);
    //Inserts a new order(base on date in order.h)onto the end of the heap and

    void remove(int index);
    //removes the node at the provided index of the heap

    vector<Order> sort();
    //sorts a heap into ascending order

    /**Access Functions*/

    int get_max() const;
    //returns the maximum value in the heap

    Order get_element(int i) const;
    //returns the order at the specified index i

	void setShipAdress(string s);
	void setCity(string s);
	void setZip(int i);
	void setState(string s);

    void displayHeap(ostream& out) const;
    //prints the heap in level order

    void displayArray(ostream& out) const;
    //prints each element in the array (heap) separated by a comma

    int get_size() const;

};


#endif // PriorityQueue_H_INCLUDED

