/*
 *  FOR CIS 22C Project
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string>
#include <ostream>

//#include "HashTable.h"
//#include "Product.h"
//#include "PriorityQueue.h"
//#include "List.h"
//#include "Customer.h"

using namespace std;

class Employee {
private:

   string id;

public:

    /** Constructor */
    Employee();

    string get_id();

};

/*
 * - Search for a customer by name

- Display unsorted customer information, including first and last name, address, phone number, order history

- View Orders by Priority

- Ship an Order

- List Database of Products

- List data sorted by primary key

- List data sorted by secondary key

         - Add a new product
         - Remove a product
         - Quit

 */

#endif /* EMPLOYEE_H_ */
