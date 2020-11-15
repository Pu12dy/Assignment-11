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

struct Node{
	// int = index, string = city name
//	pair<int,string> name;
	int index;
	string name;
	// miles apart
	int weight;
	Node* next;

	Node(){
		next = nullptr;
		weight = 0;
		index = 0;
		name = "Default";
	}
	Node(int i, string n){
		name = n;
		index = i;
		weight = 0;
		next = nullptr;
	}
};

class AdjListGraph {
private:
	int numVert;
	int size;
	vector<Node> adjList;
	int mileCount;
	vector<pair<string, string>> discoveryEdges;
	vector<pair<string, string>> backEdges;

	// A recursive function used by DFS
	void DFShelper(int vert, bool visisted[]);

public:
	// Default Constructor
	AdjListGraph(int numVert);
	// Destructor
	virtual ~AdjListGraph();
	// Returns true if AdjList is full
	bool isFull();
	// adds Vertex to AdjList
	void addVertex(int index, string name);
	// The functions adds a edge to the AdjList
	void addEdge(int originIndex, int destIndex, string destName, int miles);
	//DFS traversal of the vertices reachable from v
	void DFS(string vert);
	void printVert(int i);
	void printVertEdges(int i);
	int getMiles();
	void printDiscoveryEdges();
	void printBackEdges();

};

#endif /* ADJLISTGRAPH_H_ */
