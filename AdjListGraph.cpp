/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#include "AdjListGraph.h"

AdjListGraph::AdjListGraph(int numVert) {

}

AdjListGraph::~AdjListGraph() {
	void addEdge(string vert, int weight);
}

bool AdjListGraph::isFull(){
	return size == numVert;
}

void AdjListGraph::addVertex(pair<int, string>){
	if(isFull()){
		cout << "List is full.\n\n";
		return;
	}
	else{

	}
}

void AdjListGraph::addEdge(string vert, int weight){

	int i = 0;
	while(adjList[i].front() != vert){
		++i;
	}



}
