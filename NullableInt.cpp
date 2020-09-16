/**
* Implementation File for <code>NullableInt</code> class
* NOTE: This is an implementation file to demonstrate the rigid design
* of the <code>NullableInt</code> class.  
* <p>
* File: NullableInt.cpp
* Last edited on September 13, 2020 8:40 PM EDT 
* GNU GCC Compiler: G++ C++11
* BU ID: U29987528
* EC500: Principles of Software at Scale HW0 Fall 2020, Professor Ari Trachtenberg 
*
* @author	Ismaeel AlAlawi
* @version	%I%, %G%
* @since	1.0
*/

#include <iostream>
#include <new>
#include "NullableInt.h"

using std::cerr;

/**
* A constructor for <code>NullableInt</code> with initilization list for 
* <code>null</code> type initialization
* <p>
* The handler function called throws an exception if the initialized value for  
* <code>NullableInt</code> object is a non <code>null</code> type <code> int* </code>.
* 
* @param value_null			the expected <code>null</code> value stored in 
*							<code>NullableInt</code> initialization
* @since					1.0
*/
NullableInt::NullableInt(int* value_null) : value(value_null) {
	exceptionHandler(value_null);						// handle non null int* initialization
}  

/**
* Another constructor for <code>NullableInt</code> with initialization list for int-type initialization
* <p>
* The <code>NullableInt</code> object is dynamically allocated memory on the Free-Store dynamic memory 
* area. This allows careful memory and resource management for <code>NullableInt</code> object. No
* handler required as automatic C++11 compiler error generated for any non <code>int</code> initialization.
*
* @param value_int			the expected <code>int</code> value stored in 
*							<code>NullableInt</code> initialization
* @since 					1.0
*/
NullableInt::NullableInt(const int value_int) : value(new int(value_int)) { 
} 

/**
* Destructor for <code>NullableInt</code> 
* <p>
* <code>NullableInt</code> class makes exhaustive use of dynamic memory allocation. To avoid
* potential memory leaks, in general cases, releasing dynamically allocated memory is crucial
* to ensure proper memory and resource mangagement in large-scale software implementations.
*
* @since					1.0
*/
NullableInt::~NullableInt() {
	if (value != null) delete value;					// release memory before class instance destroyed
}

/**
* Implicit Conversion Operator for <code>NullableInt</code> to integer type
* <p>
* In order to avoid exhaustive use of operator overloading, implicit user 
* conversions are needed to implicitly convert <code>NullableInt</code> to 
* primitive <code>int</code> type. A reference to integer is required to 
* allow usage of lvalue and rvalue operations. 
*
* @return 					<code>int</code> stored value
* @since					1.0
*/
NullableInt::operator int&() {
	return *this->value;							    // de-reference and return stored int value
}  

/**
* Assignment operator overload for assigning <code>null</code> type to 
* <code> NullableInt</code> object
* <p> Effective practice to handle self assignment. Memory leak bypassed
* by de-allocation of existing memory even if that's the same as assigning
* to <code>null</code>, for software implementation consistency. Effective 
* practice to return object address with <code>operator=</code>.
*
* @param value 				expected <code>null</code> value asssigned
*							to <code>NullableInt</code> object
* @return 					<code>NullableInt&</code> object self for chaining
* @since					1.0
*/
NullableInt& NullableInt::operator=(const int* value) {
	exceptionHandler(value);						   // handle non null int* assignment
	if (this->value == value) return *this; 		   // assignment to self check
	if (this->value != null) {						   // free up pre-allocated memory
		delete this->value;							   
		this->value = null;							   // re-assign to null
	}
	return *this;									   // return object self for chaining
}

/**
* Assignment operator overload for assigning <code>int</code> type to
* <code>NullableInt</code> object
* <p> Effective practice to handle self assignment. Memory leak bypassed
* by de-allocation of existing memory, and allocation of new memory thereof.
* Effective practice to return object address with <code>operator=</code>.
* 
* @param value 				expected <code>int</code> type value assigned to 
* 							<code>NullableInt</code> object
* @return					<code>NullableInt&</code> object self for chaining
* @since					1.0
*/
NullableInt& NullableInt::operator=(const int& value) {
	if (this->value == &value) return *this; 		  // assignment to self check
	if (this->value != null) delete this->value; 	  // free up pre-allocated memory
	this->value = new int(value);					  // allocate new memory
	return *this; 									  // return object self for chaining
}

/**
* <code>NullableInt</code> method checks whether or not object is null 
*
* @return					<code>true</code> if the stored value in the
*							<code>NullableInt</code> object is <code>null</code>; 
*							<code>false</code> otherwise.
* @since					1.0
*/
bool NullableInt::isNull() const {
	if (this->value == null) return true;			// check if pointer is null
	return false;									// no jump means false
} 

/**
* Exception Handler for <code>NullableInt</code> object
* <p> The exception handler checks whether or not a non <code>null</code> type <code>int*</code> memory address
* is either assigned to <code>NullableInt</code>, or initialized. In both cases, an exception is thrown and displays
* an error message on the standard error stream. The <code>template</code> used here is to maintain the  
* <code>const</code> integrity of the parameters in the <code>null</code> type <code>operator=</code>.  
*
* @param value 				the expected <code>int*</code> memory address value
* @throws value 			non <code>null</code> type <code>int*</code>
*							memory address value 
* @since					1.0
*/
template<class T> void NullableInt::exceptionHandler(T *value) const {
	try {
		if (value != null) throw value;				// throw exception and print for non null int*
	}
	catch(...) {
		cerr << "Exception: cannot initialize/assign a variable of type 'NullableInt' with " << 
				"an lvalue of non-null type 'int *'\n";
	}
}
