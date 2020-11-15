/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#include "header.h"
#include "AdjListGraph.h"
#include "AdjMatrixGraph.h"
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
	 * Inputing a List of City Names from provided data
	 *************************************************************************/
	vector<string> cityNames;
	cityNames.push_back("Atlanta");
	cityNames.push_back("Boston");
	cityNames.push_back("Chicago");
	cityNames.push_back("Dallas");
	cityNames.push_back("Denver");
	cityNames.push_back("Houston");
	cityNames.push_back("Kansas City");
	cityNames.push_back("Los Angeles");
	cityNames.push_back("Miami");
	cityNames.push_back("New York");
	cityNames.push_back("San Francisco");
	cityNames.push_back("Seattle");

	AdjListGraph partA(cityNames.size());

	for( int i = 0; i < int(cityNames.size()); ++i){
		partA.addVertex(i, cityNames.at(i));
	}


	// Atlanta
	partA.addEdge(0, 9, "New York", 888);
	partA.addEdge(0, 6, "Kansas City", 864);
	partA.addEdge(0, 3, "Dallas", 781);
	partA.addEdge(0, 5, "Houston", 810);
	partA.addEdge(0, 8, "Miami", 661);
	// Boston
	partA.addEdge(1,9, "New York", 214);
	partA.addEdge(1,2, "Chicago", 983);
	// Chicago
	partA.addEdge(2, 11, "Seattle", 2097);
	partA.addEdge(2, 4, "Denver", 1003);
	partA.addEdge(2, 6, "Kansas City", 533);
	partA.addEdge(2, 9, "New York", 787);
	partA.addEdge(2, 1, "Boston", 983);
	// Dallas
	partA.addEdge(3, 7, "Los Angeles", 1435);
	partA.addEdge(3, 6, "Kansas City", 496);
	partA.addEdge(3, 0, "Atlanta", 781);
	partA.addEdge(3, 5, "Houston", 239);
	// Denver
	partA.addEdge(4, 5, "Seattle", 1331);
	partA.addEdge(4, 10, "San Francisco", 1267);
	partA.addEdge(4, 7, "Los Angeles", 1015);
	partA.addEdge(4, 6, "Kansas City", 599);
	partA.addEdge(4, 2, "Chicago", 1003);
	// Houston
	partA.addEdge(5, 3, "Dallas", 239);
	partA.addEdge(5, 0, "Atlanta", 810);
	partA.addEdge(5, 8, "Miami", 1187);
    //Kansas City
    partA.addEdge(6, 3, "Dallas", 496);
    partA.addEdge(6, 7, "Los Angeles", 1663);
    partA.addEdge(6, 4, "Denver", 599);
    partA.addEdge(6, 0, "Atlanta", 864);
    partA.addEdge(6, 2, "Chicago", 533);
    partA.addEdge(6, 9, "New York", 1260);
    //Los Angeles
    partA.addEdge(7, 6, "Kansas City", 1663);
    partA.addEdge(7, 4, "Denver", 1015);
    partA.addEdge(7, 10, "San Francisco", 381);
    partA.addEdge(7, 3, "Dallas", 1435);
    //Miami
    partA.addEdge(8, 0, "Atlanta", 661);
    partA.addEdge(8, 5, "Houston", 1187);
    //New York
    partA.addEdge(9, 1, "Boston", 214);
    partA.addEdge(9, 0, "Atlanta", 888);
    partA.addEdge(9, 2, "Chicago", 787);
    partA.addEdge(9, 6, "Kansas City", 1260);
    //San Fransisco
    partA.addEdge(10, 4, "Denver", 1267);
    partA.addEdge(10, 7, "Los Angeles", 381);
    partA.addEdge(10, 11, "Seattle", 807);
    //Seattle
    partA.addEdge(11, 10, "San Francisco", 807);
    partA.addEdge(11, 4, "Denver", 1331);
    partA.addEdge(11, 2, "Chicago", 2097);

//	for(int i = 0; i < int(cityNames.size()); ++i){
//		partA.printVertEdges(i);
//		cout << endl;
//	}
//
//	cout << endl << endl;

	/**************************************************************************
	 * PART A
	 *************************************************************************/

	cout << "******************************************************************\n"
		 <<	"**********    Part A - DFS starting at Kansas City      **********\n"
		 << "******************************************************************\n\n";
	cout << "DFS:\n";
	partA.DFS("Kansas City");
	cout << "\n\nTotal miles: " << partA.getMiles();

	cout << "\n\nDiscovery Edges:\n";
	partA.printDiscoveryEdges();

	cout << "\n\nBack Edges:\n";
	partA.printBackEdges();

	/**************************************************************************
	 * PART B
	 *************************************************************************/

	cout << "\n\n******************************************************************\n"
		 <<	"**********    Part B - BFS starting at Kansas City      **********\n"
		 << "******************************************************************\n\n";

	AdjMatrixGraph partB;
	partB.addVertex(cityNames);
	partB.addEdges(0, 9, 888);
	partB.addEdges(0, 6, 864);
	partB.addEdges(0, 3, 781);
	partB.addEdges(0, 5, 810);
	partB.addEdges(0, 8, 661);
	partB.addEdges(1, 9, 214);
	partB.addEdges(1, 2, 983);
	partB.addEdges(2, 11, 2097);
	partB.addEdges(2, 4,  1003);
	partB.addEdges(2, 6,  533);
	partB.addEdges(2, 9,  787);
	partB.addEdges(3, 7,  1435);
	partB.addEdges(3, 6, 496);
	partB.addEdges(3, 5,  239);
	partB.addEdges(4, 5,  1331);
	partB.addEdges(4, 10,  1267);
	partB.addEdges(4, 7,  1015);
	partB.addEdges(4, 6, 599);
	partB.addEdges(5, 8, 1187);
	partB.addEdges(6, 7,  1663);
	partB.addEdges(6, 9,  1260);
	partB.addEdges(7, 10,  381);
	partB.addEdges(10, 11,  807);

	cout << "Adjacency Matrix:\n";
	partB.printMatrix();
	cout << "\n\nBFS:\n";

	partB.BFS(6);

	return EXIT_SUCCESS;
}







































