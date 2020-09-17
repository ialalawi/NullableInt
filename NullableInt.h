/**
* NullableInt is a user-defined class that can store a possibly
* null-value int, but otherwise behave like an int. This is a
* particularly useful object to simulate Java Integer behavior 
* which can take on a null value. The object behaves exactly 
* like an int, when taking a non-null value, in terms of its
* operational use, i.e. usage of >>, <<, *=, ++, etc. operators
* are all implicitly implemented in NullableInt. The null value
* is assigned a constant, which is the preferred C+11 counterpart
* nullptr, rather than using the C-construct NULL. The entire 
* repository is broken down into three sections: design, 
* implementation, and testing. The files corresponding to each:
* <ul> 
* <li> (Design) NullableInt.h
* <li> (Implementation) NullableInt.cpp
* <li> (Testing) Testing.cpp
* </ul> 
* <h2>References:</h2>
* <ul>
* <li> <a href = "https://www.oracle.com/technical-resources/articles/java/javadoc-tool.html#@since">
* 	   How to Write Doc Domment for the Javadoc Tool </a> by © 2020 Oracle. Reference for javadoc
*	   official documentation. 
* <li> <a href = "https://github.com/trachten/cpisync/blob/master/include/CPISync/Aux/Auxiliary.h">
*	   CPISync project Auxiliary.h file </a> developed at Boston University by Ari Trachtenberg and
*	   Sean Brandenburg. Reference for javadoc documentation examples and implementation. 
* <li> <a href = "https://www.amazon.com/Introduction-Programming-3rd-Daniel-Liang/dp/0133252817"> 
*	   Introduction to Programming with C++ (3rd Edition) </a> by Y Daniel Liang. Reference for 
*	   C++ OOP, exception handling, dynamic memory allocation, and operator overloading revision. 
* <li> <a href = "https://stackoverflow.com/"> Stack Overflow </a> pre-answered questions (8 yrs+ ago).
*	   Reference used to look up and fix run-time and compiler errors accordingly in implementation,
*	   and testing.
* <li> <a href = "https://agile.bu.edu/fw/EC500/HomeworkZero"> EC500: Principles of Software at Scale
* 	   Fall 2020 FOSWIKI Course Webpage and HomeworkZero </a> by Ari Trachtenberg. Reference for this
*	   HomeworkZero assignment and lecture note revision for javadoc documentation, and effective
*      C++11 practices.
* </ul>
* <p>
* File: NullableInt.h
* Last edited on September 13, 2020 6:01 PM EDT 
* GNU GCC Compiler: G++ C++11
*
* @author	Ismaeel AlAlawi
* @version	%I%, %G%
* @since	1.0
*/

#ifndef NULLABLEINT_H
#define NULLABLEINT_H										// effective, safe practice to add include guards

const auto null = nullptr;  								// user-defined null value constant

class NullableInt {
	public:
		NullableInt(int*); 									// null-type initialization
		NullableInt(const int);  							// int-type initialization
		~NullableInt();										// object dynamic memory destructor
		bool isNull() const;     							// null-type check
		operator int&();  							   	 	// int-type implicit conversion operator
		NullableInt& operator=(const int* const);   		// null-type assignment
		NullableInt& operator=(const int&);					// int-type assignment
	protected:
		int *value;  										// value stored in NullableInt object (null or int)
		template<class T> void exceptionHandler(T*) const;	// handles non-null int * memory address exceptions
};

#endif // NULLABLEINT_H
