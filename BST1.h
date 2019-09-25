#ifndef BST1_H_
#define BST1_H_

#include <cstddef>
#include <string>
#include <assert.h>

using namespace std;
template<class bstdata>
class BST1 {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;

        Node(bstdata newdata){
            data = newdata;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertHelper(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrintHelper(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyHelper(Node* copy);
    //recursive helper function to the copy constructor

    void destructorHelper(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bstdata searchHelper(Node* root, bstdata data) const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimumHelper(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximumHelper(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* removeHelper(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSizeHelper(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeightHelper(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    BST1();
    //Instantiates a new BST

    BST1(const BST1 &bst);
    //copy constructor

    ~BST1();
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize() const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bstdata search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the preOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};

template<class bstdata>
void BST1<bstdata>::insertHelper(Node* root, bstdata data)
{
	if(data == root -> data)
		return;
	else if(data < root -> data)
	{
		if(root -> left == NULL)
			root -> left = new Node(data);
		else
			insertHelper(root -> left, data);
	}
	else
	{
		if(root -> right == NULL)
			root -> right = new Node(data);
		else
			insertHelper(root -> right, data);
	}
}

template<class bstdata>
void BST1<bstdata>::insert(bstdata data)
{
	if (root == NULL)
		root = new Node(data); //if the tree is empty insert the value at the root
	else
	    insertHelper(root, data); //Otherwise, call the helper function passing it the root
}

template<class bstdata>
void BST1<bstdata>::inOrderPrintHelper(ostream& out, Node* root) const
{
	if(root == NULL){
		return;
	}else{
		inOrderPrintHelper(out, root -> left);
		out << root -> data << endl;
		inOrderPrintHelper(out, root -> right);
	}
}

template<class bstdata>
void BST1<bstdata>::inOrderPrint(ostream& out) const
{
	inOrderPrintHelper(out, root);
}

template<class bstdata>
void BST1<bstdata>::preOrderPrintHelper(ostream& out, Node* root) const
{
	if(root == NULL){
		return;
	}else{
		out << root -> data << endl;
		preOrderPrintHelper(out, root -> left);
		preOrderPrintHelper(out, root -> right);
	}
}

template<class bstdata>
void BST1<bstdata>::preOrderPrint(ostream& out) const
{
	preOrderPrintHelper(out, root);
}

template<class bstdata>
void BST1<bstdata>::postOrderPrintHelper(ostream& out, Node* root) const
{
	if(root == NULL){
		return;
	}else{
		postOrderPrintHelper(out, root -> left);
		postOrderPrintHelper(out, root -> right);
		out << root -> data << endl;
	}
}

template<class bstdata>
void BST1<bstdata>::postOrderPrint(ostream& out) const
{
	postOrderPrintHelper(out, root);
}

template<class bstdata>
BST1<bstdata>::BST1()
{
	root = NULL;
}
/*
template<class bstdata>
void BST1<bstdata>::copyHelper(Node* copy)
{
	if(copy == NULL)
		return;
	else
	{
		Node* N = new Node(copy -> data);
		copyHelper(copy -> left);
		N -> left = copy -> left;
		copyHelper(copy -> right);
		N -> right = copy -> right;
	}
}

template<class bstdata>
BST1<bstdata>::BST1(const BST1 &bst)
{
	copyHelper(bst.root);
}
*/
template<class bstdata>
void BST1<bstdata>::destructorHelper(Node* root)
{
	if(root == NULL)
		return;
	else
	{
		destructorHelper(root -> left);
		destructorHelper(root -> right);
		delete root;
		root = NULL;
	}
}

template<class bstdata>
BST1<bstdata>::~BST1()
{
	destructorHelper(root);
}

template<class bstdata>
bstdata BST1<bstdata>::searchHelper(Node* root, bstdata data) const
{
    if(data == root -> data)
    	return root -> data;
    else if(data < root -> data)
    {
    	if(root -> left == NULL)
    		return data;
    	else
    		return searchHelper(root -> left, data);
    }
    else
    {
    	if(root -> right == NULL)
    		return data;
    	else
    		return searchHelper(root -> right, data);
    }
    return data;
}

template<class bstdata>
bstdata BST1<bstdata>::search(bstdata data) const
{
	assert(!isEmpty());
	if(data == root -> data)
		return root -> data;
	else
    	return searchHelper(root, data); //call helper function
}

template<class bstdata>
bstdata BST1<bstdata>::minimumHelper(Node* root) const
{
	if(root -> left != NULL)
		return minimumHelper(root -> left);
	else
		return root -> data;
}

template<class bstdata>
bstdata BST1<bstdata>::minimum() const
{
	assert(!isEmpty());
	return minimumHelper(root);
}

template<class bstdata>
bstdata BST1<bstdata>::maximumHelper(Node* root) const
{
	if(root -> right != NULL)
		return maximumHelper(root -> right);
	else
		return root -> data;
}

template<class bstdata>
bstdata BST1<bstdata>::maximum() const
{
	assert(!isEmpty());
	return maximumHelper(root);
}

template<class bstdata>
bool BST1<bstdata>::isEmpty() const
{
	return (root == NULL);
}

template<class bstdata>
typename BST1<bstdata>::Node* BST1<bstdata>::removeHelper(Node* root, bstdata data)
{
	if(root == NULL)
		return root;
	else if(data < root -> data)
		root -> left = removeHelper(root -> left, data);
	else if(data == root -> data)
	{
		if(root -> left == NULL && root -> right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root -> left != NULL && root -> right == NULL)
		{
			Node* temp = root;
			root = root -> left;
			delete temp;
		}
		else if(root -> left == NULL && root -> right != NULL)
		{
			Node* temp = root;
			root = root -> right;
			delete temp;
		}
		else
		{
			root -> data = minimumHelper(root -> right);
			root -> right = removeHelper(root -> right, minimumHelper(root -> right));
		}
	}
	else
			root -> right = removeHelper(root -> right, data);
	return root;
}

template<class bstdata>
void BST1<bstdata>::remove(bstdata data)
{
	assert(!isEmpty());
	assert(search(data) != data);
	root = removeHelper(root, data);
}

template<class bstdata>
void BST1<bstdata>::getSizeHelper(Node* root, int& size) const
{
	if(root == NULL)
		return;
	else
	{
		size++;
		getSizeHelper(root -> left, size);
		getSizeHelper(root -> right, size);
	}
}

template<class bstdata>
int BST1<bstdata>::getSize() const
{
	int size = 0;
	getSizeHelper(root, size);
	return size;
}

template<class bstdata>
bstdata BST1<bstdata>::getRoot() const
{
	assert(!isEmpty());
	return root -> data;
}

template<class bstdata>
int BST1<bstdata>::getHeightHelper(Node* root) const
{
	if(root == NULL)
		return -1;
	else
	{
		int L = 1 + getHeightHelper(root -> left);
		int R = 1 + getHeightHelper(root -> right);
		if(L > R)
			return L;
		else
			return R;
	}
}

template<class bstdata>
int BST1<bstdata>::getHeight() const
{
	return getHeightHelper(root);
}

#endif /* BST1_H_ */
