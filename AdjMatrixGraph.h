/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/

#ifndef ADJMATRIXGRAPH_H_
#define ADJMATRIXGRAPH_H_
#include "header.h"

class AdjMatrixGraph {
private:
	static const int SIZE = 12;
	string cityNames[SIZE];
	int    adjMatrix[SIZE][SIZE];
	bool   visited[SIZE] {false};
	bool   allVisited = false;
	vector<pair<int, int>> myQ;
	//void BFShelper(int vert, vector<pair<int, int>> myQ);

public:
	AdjMatrixGraph();
	virtual ~AdjMatrixGraph();
	void addVertex(vector<string> names);
	void addEdges(int indexA, int indexB, int weight);
	void printMatrix();
	void BFS(int vert);

};

#endif /* ADJMATRIXGRAPH_H_ */
