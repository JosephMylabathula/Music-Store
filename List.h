
#ifndef LIST_H_
#define LIST_H_
#include <cstddef> //for NULL
#include <iostream>
#include <assert.h>
using namespace std;

/************************************************************/
template <class listdata>
class List
{
	private:
	    struct Node
		{
	    	listdata data;
	        Node* next;
	        Node* linkprevious;
	        Node(listdata newData)
	        {
    	        data = newData;
    	        next     = NULL;
    	        linkprevious = NULL;
    	    }
	    };

	    Node* start;
	    Node* stop;
	    Node* iterator;
   		int length;

   		void reversedisplayList(Node* node) const;
   		//Helper function for the public reversedisplayList() function.
        //Recursively displayLists the data in a List in reverse.

   		bool isSorted(Node* node) const;
        //Helper function for the public isSorted() function.
        //Recursively determines whether a list is sorted in ascending order.

		int binarySearch(int low, int high, listdata data)const;
		//Recursively search the list by dividing the search space in half
		//Returns the index of the element, if it is found in the List
		//Returns -1 if the element is not in the List
		//Post: The iterator location has not been changed
	public:
	    	    /**Constructors and Destructors*/

	    List();
	    //Default constructor; initializes and empty list
	    //Postcondition:

        List(const List<listdata> & list);
	    //Default constructor; initializes and empty list
	    //Postcondition:

	    ~List();
	    //Destructor. Frees memory allocated to the list
   		//Postcondition:

	    /**Accessors*/

	    listdata getStart() const;
	    //Returns the first data in the list
	    //Precondition:

	    void moveToIndex(int index);
	    listdata getStop() const;
	    //Returns the last data in the list
	    //Precondition:
void operator=(const List &M );
	    bool isEmpty() const;
	    //Determines whether a list is empty.

	    int getLength() const;
	    //Returns the length of the list

	    /**Manipulation Procedures*/

	    void removeStop();
	    //Removes the value of the last data in the list
	    //Precondition:
	    //Postcondition:

	    void removeStart();
	    //Removes the value of the first data in the list
	    //Precondition:
	    //Postcondition:

	    void insertStop (listdata data);
	    //Inserts a new data at the end of the list
	    //If the list is empty, the new data becomes both first and last
	    //Postcondition:

	    void insertStart(listdata data);
	    //Inserts a new data at the start of the list
	    //If the list is empty, the new data becomes both first and last
	    //Postcondition:

	    /**Additional List Operations*/

	    void displayList(ostream& os) const;
	    //displayLists to the console the value of each data in the list sequentially
	    //and separated by a blank space
	    //displayLists nothing if the list is empty
	    //displayLists a empty newline character if it's empty..

		void reversedisplayList() const;
	    //displayLists to the console the value of each data in the list in reverse
	    //and separated by a blank space
	    //displayLists nothing if the list is empty
	    //displayLists a empty newline character if it's empty..

		void startIterator();
        //moves the iterator to the start of the list

		void removeIterator();
        //removes the element currently pointed to by the iterator. Iterator then points to NULL.

	    void insertIterator(listdata data);
        //inserts an element after the node currently pointed to by the iterator

		void moveIterNext();
        //moves the iterator up by one node towards stop

		void reverseIterator();
        //moves the iterator down by one node towards start

		listdata getIterator()const;
        //returns the element currently pointed at by the iterator

		bool offEnd()const;
        //returns whether the iterator is off the end of the list, i.e. is NULL

	    void displayListNumberedList(ostream &out)const;
        //displayLists the contents of the linked list to the screen in the format #: <element> followed by a newline

		bool operator==(const List& A);
		//compares this list to see if it contains the same data, in the same order as another list.

		bool isSorted() const;
		//Wrapper function that calls the isSorted helper function to determine whether
		//a list is sorted in ascending order.
		//We will consider that a list is trivially sorted if it is empty.
		//Therefore, no precondition is needed for this function

		int getIndex() const;
		//Indicates the index of the Node where the iterator is currently pointing
		//Nodes are numbered starting at 1 through the length of the list
		//Pre: length != 0
		//Pre: !offEnd()

		void advanceToIndex(int index);
		//Moves the iterator to the node whose index number is specified in the parameter
		//Nodes are numbered starting at 1 through the length of the List
		//Pre: length != 0
		//Pre: index <= length

		/**Access Functions*/
		int linearSearch(listdata data) const;
        //Searchs the list, element by element, from the start of the List to the end of the List
        //Returns the index of the element, if it is found in the List
        //Does not call the indexing functions in the implementation
        //Returns -1 if the element is not in the List
        //Pre: length != 0
        //Post: The iterator location has not been changed



		int binarySearch(listdata data)const;
		//Returns the index where data is located in the List
		//Calls the private helper function binarySearch to perform the search
		//Pre: length != 0
		//Pre: List is sorted (must test on a sorted list)
		//Post: The iterator location has not been changed
};
/************************************************************/
template<class listdata>
List<listdata>::List()
{
    start = NULL;
    stop = NULL;
    iterator = NULL;
    length = 0;
}
/************************************************************/
//(List<Book>) (const List<Book>&)
template<class listdata>
List<listdata>::List(const List<listdata> &list)
{
    if(list.start == NULL) //If the original list is empty, make an empty list for this list
    {
        start = stop = iterator = NULL;
    }
    else
    {
        start = new Node(list.start->data); //calling Node constructor
        Node* temp = list.start; //set a temporary node pointer to point at the first of the original list
        iterator = start; //set iterator to point to first node of the new list

        while(temp->next != NULL)
        {
            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator->next->linkprevious = iterator; //connect the new node to previous node
            iterator = iterator->next; //advance to this new node
        }
        stop = iterator; //Why do I need this line of code?
        iterator = NULL;
    }
    length = list.length;
}
/************************************************************/
template <class listdata>
List<listdata>::~List()
{
    Node* b = start;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}
/************************************************************/
template <class listdata>
listdata List<listdata>::getStart() const
{
    assert(length!=0);
    return start->data;
}
/************************************************************/
template <class listdata> listdata
List<listdata>::getStop() const
{
    assert(length!=0);
    return stop->data;
}
/************************************************************/
template <class listdata>
bool List<listdata>::isEmpty() const
{
    if(length==0)
        return true;

    return false;
}
/************************************************************/
template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}
/************************************************************/
template <class listdata>
void List<listdata>::removeStop()
{
    assert(length!=0);
    if(start->next == NULL)
    {
        delete stop;
        start = NULL;
        stop = NULL;
        iterator = NULL;
        length=0;
    }else{
		iterator ->linkprevious->next = NULL;
        stop = iterator->linkprevious;
        delete iterator;
        iterator = NULL;
        length--;
    }
}
/************************************************************/
template <class listdata>
void List<listdata>::removeStart()
{
    assert(length!=0);
    if(start->next == NULL)
    {
        delete start;
        start = stop = NULL;
        iterator = NULL;
        length=0;
    }else{
        iterator ->next->linkprevious = NULL;
        start = iterator->next;
        delete iterator;
        iterator = NULL;
        length--;
    }
}
/************************************************************/
template <class listdata>
void List<listdata>::insertStop (listdata data)
{
    Node* N = new Node(data);
    if(length == 0)
    {
        start = stop = N;
    }else{
        N->linkprevious = stop;
        stop->next = N;
        stop = N;
    }
    length++;
}
/************************************************************/
template <class listdata>
void List<listdata>::insertStart(listdata data)
{
	Node* N = new Node(data);
    if(length == 0)
    {
        start = stop = N;
    }else{
        N->next = start;
        start->linkprevious = N;
        start = N;
    }
    length++;
}
/************************************************************/
template <class listdata>
void List<listdata>::reversedisplayList() const
{
    Node* temp = stop; //create a temporary iterator
    reversedisplayList(temp);
}
/************************************************************/
template <class listdata>
void List<listdata>::reversedisplayList(Node* node) const
{
    if(node == NULL)//base case
    {
        cout << "\n";
    }else{
        cout << node->data << " ";
    	node = node->linkprevious; //move to previous Node in the List
    	reversedisplayList(node);

    }
}
/************************************************************/
template <class listdata>
bool List<listdata>::isSorted() const
{

    Node* temp = start; //create a temporary iterator
    return isSorted(temp);
}
/************************************************************/
template <class listdata>
bool List<listdata>::isSorted(Node* node) const
{
    if (node == NULL || node->next != NULL) {//base case
        return true;
    }else if(node > node->next){
        return false;
    }else{
        node = node->next;
        return isSorted(node);
    }
}
/************************************************************/
template <class listdata>
void List<listdata>:: startIterator()
{
    iterator = start;
}
/************************************************************/

template <class listdata>
void List<listdata>::removeIterator()
{
    assert(!offEnd());
    if( iterator == stop){
        removeStop();

    }else if ( iterator == start){
        removeStart();
    }else{
		iterator->linkprevious->next = iterator->next;
        iterator->next->linkprevious = iterator->linkprevious;
        delete iterator;
        iterator = NULL;
        length--;
    }
}
/************************************************************/
template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(!offEnd());
	if(iterator == stop){
		insertStop (data);

 	}else if(iterator == start){
		insertStart(data);
	}else{
		Node* N = new Node(data);

		N->next = iterator->next;
		N->linkprevious = iterator->next->linkprevious;
		iterator->next->linkprevious = N;
		iterator->next = N;
		length++;
	}
}
/************************************************************/
template <class listdata>
void List<listdata>::moveIterNext()
{
    assert(iterator != NULL);
    iterator = iterator->next;

}
/************************************************************/
template <class listdata>
void List<listdata>::reverseIterator()
{
    assert(iterator != NULL);
    iterator = iterator->linkprevious;
}
/************************************************************/
template <class listdata>
listdata List<listdata>::getIterator()const
{
    assert(iterator != NULL);
    return iterator->data;
}
/************************************************************/
template <class listdata>
bool List<listdata>::offEnd()const
{
    return iterator == NULL;
}
/************************************************************/
template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    Node* temp1 = start;
    Node* temp2 = list.start;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class listdata>
void List<listdata>:: operator=(const List &list )


{
    if(list.start == NULL) //If the original list is empty, make an empty list for this list
    {
        start = stop = iterator = NULL;
    }
    else
    {
        start = new Node(list.start->data); //calling Node constructor
        Node* temp = list.start; //set a temporary node pointer to point at the first of the original list
        iterator = start; //set iterator to point to first node of the new list

        while(temp->next != NULL)
        {
            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator->next->linkprevious = iterator; //connect the new node to previous node
            iterator = iterator->next; //advance to this new node
        }
        stop = iterator; //Why do I need this line of code?
        iterator = NULL;
    }
    length = list.length;
}


/************************************************************/
template <class listdata>
void List<listdata>::displayListNumberedList(ostream &out)const
{
    Node* temp = start; //create a temporary iterator
    int i=1;
    while (temp != NULL) { //if the list is not empty
    out << "\nOrder " <<i <<": \n\n" << temp->data << "\n";
    temp = temp->next; //move to next Node in the List
    i++;
    }
    cout << "\n";
}
/************************************************************/
template <class listdata>
int List<listdata>::getIndex() const
{
	assert(!offEnd());
	int index(1);
	Node* temp = start;
	while(temp != iterator)
	{
		temp = temp->next; //move to next Node in the List
		index++;
	}
	return index;
}
/************************************************************/
template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
	assert(length != 0);
	assert(index > 0 && index <= length);
	iterator = start;
	int i = 1;
	while(i != index)
	{
		iterator = iterator->next;
		i++;
	}
}
/************************************************************/
template <class listdata>
int List<listdata>::linearSearch(listdata data) const
{
    assert(length !=0);

    Node* temp = start;
    int i = 1;
    while(temp != NULL)
    {
    	if(temp->data == data)
    	{
    		return i;
    	}
   		temp = temp->next;
   		i++;
    }
    return -1;
}

/************************************************************/
template <class listdata>
int List<listdata>::binarySearch(listdata data)const
{
	assert(length != 0);
	int low = 1;
	int high = getLength();
	return binarySearch(low, high, data);
}

/************************************************************/
template <class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data)const
{
    assert(isSorted());

	if(low > high )
		return -1;

	int mid = low + (high - low)/2;
	//define a temp iterator and advance it to the mid
	Node* temp = start;
	int i = 1;
	while(i != mid)
	{
		temp = temp->next;
		i++;
	}
	//if mid data is equal to target return mid index
	if(temp->data == data)
    {
        return mid;
    }
    //if mid data is grater than target, continue search between low to mid-1 index
    else if(data < temp->data)
    {
        return binarySearch(low, mid-1, data);
    }
    //if mid data is less than target, continue searching between mid+1 to high index
    else if(data > temp->data)
    {
		return binarySearch(mid+1, high, data);
    }
}

/************************************************************/
template <class listdata>
void List<listdata>::displayList(ostream& os)const
{
    Node* temp = start; //create a temporary iterator
    while (temp != NULL) {
    	os << temp->data<<endl;
    	temp = temp->next; //move to next Node in the List
    }

}


template <class listdata>
void List<listdata>:: moveToIndex(int index)
{
    assert(length != 0);
    assert(index > 0 && index <= length);
    iterator = start;
    int i = 1;
    while(i != index)
    {
        iterator = iterator->next;
        i++;
    }

}




/************************************************************/
#endif /* LIST_H_ */
