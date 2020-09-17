/**
* Testing File for <code>NullableInt</code> class
* NOTE: This is a testing file to demonstrate that the
* <code>NullableInt</code> class is working as expected. 
* <p> The testing file tests four properties of <code>NullableInt</code>:
* <ul>
* <li> <code>null</code> Initialization 
* <li> <code>null</code> Check 
* <li> <code>int</code> Assignment 
* <li> <code>int</code> Operations 
* </li>
* <p>
* It accomplishes the latter parts by looping to find the factorial of 9, thus
* the expected console output is 362880, after successful compilation.
* <p> 
* File: Testing.cpp
* Last edited on September 13, 2020 8:45 PM EDT 
* GNU GCC Compiler: G++ C++11
*
* @author	Ismaeel AlAlawi
* @version	%I%, %G%
* @since	1.0
*/

#include "NullableInt.cpp"

using std::endl;
using std::cout;

int main() {
  NullableInt prod = null;							// initialize object as null
  for (int ii=1; ii<10; ii++) 					    // loop-based factorial
    if (prod.isNull())								// check if object stores null
      prod = ii;									// assign object to int
    else
      prod = prod * ii;								// update by int product

    cout << prod << endl;							// print object directly to output
}
