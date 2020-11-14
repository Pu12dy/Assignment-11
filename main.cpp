/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#include "header.h"
/******************************************************************************
 * Assignment 11 - DFS & BFS
 * Part A -
 * This part of the program will perform a Depth-First Search using the provided
 * information and starting at Kansas CIty (always choose the edge with the
 * smallest mileage). The program will output the discovery edges and the back
 * edges as well as the origin vertex and destination vertex. This part will
 * utilize an Adjacency list structure.
 * Part B -
 * This part of the program will perform a Breadth-First Search using the provided
 * information and starting at Kansas City (always choose the edge with the
 * smallest mileage).  The program will output the discovery edges and the back
 * edges as well as the origin vertex and destination vertex. This part will
 * utilize an Adjacency Matrix structure.
 *****************************************************************************/

/******************************************************************************
 * PringHeader
 * 	This function receives an assignment name, type and number then outputs the
 * 	appropriate class heading.
 * 	asType is defaulted to Lab as there are more labs than Assignments.
 * 	==> returns nothing - This will output the class heading
 *****************************************************************************/
void PrintHeader(const string PROGRAMMER,		  	// IN & OUT - Programmer name
				 const string CLASS_NAME,		  	// IN & OUT - Class name
				 const string CLASS_TIME,         	// IN & OUT - Class period
				 const string ASSIGN_NAME,		  	// IN & OUT - assignment name
				 const string PROGRAM_DESCRIPTION,
				 const int    ASSIGN_NUM,		  	// IN & OUT - assignment #
				 const char   ASSIGN_TYPE = 'L'); 	// IN & OUT - assignment type
												  	//	 ('L' = Lab,
												    //	 'A' = Assignment)

int main(){
	/**************************************************************************
	* CONSTANTS
	* -------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* -------------------------------------------------------------------------
	* PROGRAMMER        : Programmer's Name
	* CLASS_NAME        : Student's Course
	* CLASS_PERIOD      : Class Days and Times
	* ASSIGNMENT_NAME   : Assignment Name
	* ASSIGNMENT_NUMBER : Assignment Number
	* ASSIGNMENT_TYPE   : Type of Assignment
	**************************************************************************/
	const string PROGRAMMER        = "Jeff Purdy & Breighton Kohl";
	const string CLASS_NAME        = "CS1D";
	const string CLASS_PERIOD      = "MW: 2:30 PM";
	const string ASSIGNMENT_NAME   = "BFS & DFS";
	const int    ASSIGNMENT_NUMBER = 11;
	const char   ASSIGNMENT_TYPE   = 'A';
	const string PROGRAM_DESCRIPTION = "This Program will perform a Depth-First Search and a Breadth-First\n"
										"Search with the provided information. The Depth-First Search will\n"
										"utilize an Adjacency list structure and the Breadth-First Search\n"
										"utilize an Adjacency Matrix structure.\n";

	/**************************************************************************
	 *  OUTPUT - Outputs of the class heading.
	 *************************************************************************/
	PrintHeader(PROGRAMMER,
			    CLASS_NAME,
				CLASS_PERIOD,
				ASSIGNMENT_NAME,
				PROGRAM_DESCRIPTION,
				ASSIGNMENT_NUMBER,
				ASSIGNMENT_TYPE);
	/**************************************************************************
	 *  END OF HEADER OUTPUT
	 *************************************************************************/

	/**************************************************************************
	 * PART A
	 *************************************************************************/

	cout << "******************************************************************\n"
		 <<	"**********    Part A - DFS starting at Kansas City      **********\n"
		 << "******************************************************************\n\n";

	/**************************************************************************
	 * PART B
	 *************************************************************************/

	cout << "******************************************************************\n"
		 <<	"**********    Part B - BFS starting at Kansas City      **********\n"
		 << "******************************************************************\n\n";

	return EXIT_SUCCESS;
}
