/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#ifndef ADJLISTGRAPH_H_
#define ADJLISTGRAPH_H_
#include "header.h"

class AdjListGraph {
private:
	int numVert;
	int size;
	pair<int, string> vertex;
	list <int>* adjList;
	// A recursive function used by DFS
	void DFShelper(string vert, bool visisted[]);

public:
	// Default Constructor
	AdjListGraph(int numVert);
	// Destructor
	virtual ~AdjListGraph();
	// Returns true if AdjList is full
	bool isFull();
	// adds Vertex to AdjList
	void addVertex(pair<int, string>);
	// The functions adds a edge to the AdjList
	void addEdge(string vert, int weight);
	//DFS traversal of the vertices reachable from v
	void DFS(string vert);

};

#endif /* ADJLISTGRAPH_H_ */
