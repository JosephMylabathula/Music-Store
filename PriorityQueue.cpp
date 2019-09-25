/*
 * PriorityQueue.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: maryamr
 */

#include <iostream>
#include "priorityQueue.h"

#include <vector>

#include "math.h"
#include "stddef.h"
#include <assert.h>
#include "List.h"
#include "Order.h"
using namespace std;

PriorityQueue::PriorityQueue(vector<Order> &ord)
{
	heap=&ord;
	heap_size= ord.size() - 1;
	build_heap();


}

void PriorityQueue:: build_heap()
{


int i=floor(get_size()/2);
	for ( ;i>=1 ;i--) {

	   heapify(i);

	    }
}



void PriorityQueue:: heapify(int i)
{

	int l;
	int r;
	Order temp1;
	int index_of_max=i;

	l = 2*i; //get the index of the left child of A[i] and store as l

	r = 2*i+1; //get the index of the right child of A[i] and store r

	if (l <=get_size()&& get_element(l).get_priorityShipping() > get_element(i).get_priorityShipping())

	    index_of_max = l; //update index_of_max if left is bigger


if (r <=get_size()&& get_element(r).get_priorityShipping() > get_element(i).get_priorityShipping())

	index_of_max = r; //update index_of_max if right is bigger

if (r <=get_size()&& r <=get_size() && get_element(r).get_priorityShipping() ==get_element(l).get_priorityShipping()&& get_element(r).get_priorityShipping() > get_element(i).get_priorityShipping())
	{
	if(get_element(r).compareDate() > get_element(l).compareDate())
		index_of_max = l;
	}

	if (i != index_of_max) //if A[i] was not bigger than its two children
	{
		temp1=get_element(i);

		heap->at(i)=get_element(index_of_max);

		heap->at(index_of_max)=temp1;


	   // A[i]<--->A[index_of_max] //swap, so now A[i] stored at A[index_of_max]

	   heapify( index_of_max); //recursively move through tree until restore heap property
	}


	else {

		if ((l <=get_size()&& get_element(l).get_priorityShipping()== get_element(i).get_priorityShipping() )||
				(r <=get_size()&& 	get_element(r).get_priorityShipping()== get_element(i).get_priorityShipping()))
		{


			if (get_element(l).get_priorityShipping()== get_element(i).get_priorityShipping() && get_element(l).compareDate() < get_element(i).compareDate()){

				    index_of_max = l; //update index_of_max if left is bigger
			}
			if (get_element(r).get_priorityShipping()== get_element(i).get_priorityShipping() && get_element(r).compareDate() < get_element(i).compareDate()){

				index_of_max = r; //update index_of_max if right is bigger

			}
				if (i != index_of_max) //if A[i] was not bigger than its two children
				{

	    temp1=get_element(i);


			heap->at(i)=get_element(index_of_max);

			heap->at(index_of_max)=temp1;


		   heapify( index_of_max); //recursively move through tree until restore heap property

				}


		}
	}


}




void PriorityQueue::heap_increase_key(int i, Order b)
{
Order temp1;

	    if(b.get_priorityShipping() > heap->at(i).get_priorityShipping())
	    {
            heap->at(i)=b;
	    }


while (i > 1 && heap->at(i/2).get_priorityShipping()<heap->at(i).get_priorityShipping())
	{


		// Swap parent and child
		temp1=heap->at(i);
		heap->at(i)=heap->at(i/2);
		heap->at(i/2)=temp1;
		i=i/2;

	}


	    	while (i > 1 && heap->at(i/2).compareDate()>heap->at(i).compareDate()&&b.get_priorityShipping() == heap->at(i/2).get_priorityShipping())
	    		{

	    			// Swap parent and child
	    			temp1=heap->at(i);
	    			heap->at(i)=heap->at(i/2);
	    			heap->at(i/2)=temp1;
	    			i=i/2;

	    }
	    }

void PriorityQueue::remove(int index){
assert(1<=index && index<=heap_size);
	 Order last=heap->at(heap_size);

	 heap->at(heap_size)=heap->at(index);
	 heap->at(index)= last;

    heap->erase(heap->begin()+heap_size);
    heap_size--;
    heapify(index);
    build_heap();


}


void PriorityQueue:: insert( Order b)
{

	heap->push_back(Order("",-1,-1,0));

    heap_size++;

  heap->at(heap_size)=Order("",-1,-1,0);


   heap_increase_key( heap_size, b);

}



Order PriorityQueue::get_element(int i) const
{
	return heap->at(i);
}


int PriorityQueue::get_size() const
{
    return heap_size;

}


void PriorityQueue::displayArray(ostream& out) const
{


	for(int i=1;i<=get_size();i++)
	{
	    cout<<"customer name: "<<get_element(i).getFname()<<" "<<get_element(i).getLname()<<endl<<endl;
		get_element(i).display(out);
cout<<endl<<endl;
	}
	out<<endl;
}
