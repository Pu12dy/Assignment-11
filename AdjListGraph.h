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
	list<string>* adjList;
	void DFShelper(string vert, bool visisted[]);

public:
	AdjListGraph(int numVert);
	virtual ~AdjListGraph();
	void addEdge(string vert, int weight);
	void DFS(string vert);

};

#endif /* ADJLISTGRAPH_H_ */
