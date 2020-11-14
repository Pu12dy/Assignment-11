/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#include "header.h"
/******************************************************************************
 * PringHeader
 * 	This function receives an assignment name, type and number then outputs the
 * 	appropriate class heading.
 * 	asType is defaulted to Lab as there are more labs than Assignments.
 * 	==> returns nothing - This will output the class heading
 *_____________________________________________________________________________
 * PRE-CONDITIONS
 *  The following parameters need to have a defined value prior to calling
 *  the function:
 *  	PROGRAMMER  : Programmer's name
 *      CLASS_NAME  : Class name
 *      CLASS_TIME  : Classes day and time
 *  	ASSIGN_NUM  : assignment name
 *  	ASSIGN_TYPE : assignment type
 *
 *  POST-CONDITIONS
 *   This function will output the class heading.
 *____________________________________________________________________________
 *
 * OUTPUT:
 * -------------------------------------------------------------------------
 * PROGRAMMER     : Programmer's Name
 * CLASS          : Student's Course
 * SECTION        : Class Days and Times
 * LAB_NUM        : Assignment Number
 * LAB_NAME       : Title of the Assignment
 *****************************************************************************/
void PrintHeader(const string PROGRAMMER,        	// IN & OUT - Programmer name
				 const string CLASS_NAME,        	// IN & OUT - Class name
				 const string CLASS_TIME,        	// IN & OUT - Class period
				 const string ASSIGN_NAME,	     	// IN & OUT - Assignment name
				 const string PROGRAM_DESCRIPTION,	// IN & OUT - Description of Program
				 const int    ASSIGN_NUM,        	// IN & OUT - assignment #
				 const char   ASSIGN_TYPE = 'L') 	// IN & OUT - assignment type
											     	 //	  ('L' = Lab,
											     	 //	   'A' = Assignment)
{
	cout << left;
	cout << "***************************************************\n";
	cout << "*  PROGRAMMED BY : " << PROGRAMMER << endl;
	cout << "*  "     << setw(14) << "CLASS"    << ": " << CLASS_NAME << endl;
	cout << "*  "     << setw(14) << "SECTION"  << ": " << CLASS_TIME << endl;

	// PROCESSING - This will adjust the setw's and format appropriately
	//				based on if this is a lab 'L' or assignment
	if (toupper(ASSIGN_TYPE) == 'L')
	{
		cout << "*  LAB #" << setw(9);
	}
	else
	{
		cout << "*  ASSIGNMENT #" << setw(2);
	}

	cout << ASSIGN_NUM << ": " << ASSIGN_NAME << endl;
	cout << "***************************************************\n\n";
	cout << right;

	cout << PROGRAM_DESCRIPTION << endl << endl;
}
