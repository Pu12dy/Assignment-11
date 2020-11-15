/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/

#include "AdjMatrixGraph.h"

AdjMatrixGraph::AdjMatrixGraph() {
//	cityNames[vertNum];
//	adjMatrix[vertNum][vertNum];

	for(int i = 0; i < SIZE; ++i)
	{
		for(int j = 0; j < SIZE; ++j)
			adjMatrix[i][j] = 0;
	}


}

AdjMatrixGraph::~AdjMatrixGraph() {

}

void AdjMatrixGraph::addVertex(vector<string> names){

	for(int i = 0; i < int(names.size()); ++i)
		cityNames[i] = names[i];
}

void AdjMatrixGraph::addEdges(int indexA, int indexB, int weight){
	adjMatrix[indexA][indexB] = weight;
	adjMatrix[indexB][indexA] = weight;
}

void AdjMatrixGraph::printMatrix(){
	for(int i = 0; i < SIZE; ++i)
	{
		cout << cityNames[i] << '[' << i << "] \t   ";
		for(int j = 0; j < SIZE; ++j)
			cout << adjMatrix[i][j] << "\t ";

		cout << endl;
	}
}

void AdjMatrixGraph::BFS(int vert){

	int number = myQ.size();

	if(!visited[vert])
		cout << cityNames[vert] << ' ';

	visited[vert] = true;

	for(int i = 0; i < SIZE; ++i){
		if(adjMatrix[vert][i] > 0 && !visited[i]){
			myQ.push_back(make_pair(adjMatrix[vert][i], i));
//			visited[i] = true;
		}
	}

	sort(myQ.begin(), myQ.end());

	for(int i = 0; i < int(myQ.size()); ++i){
		if(visited[myQ[i].second] != true)
			cout << cityNames[myQ[i].second] << ' ';
		visited[myQ[i].second] = true;
	}

//	cout << endl;
//	allVisited = true;
//	for(int i = 0; i < SIZE; ++i){
////		if(!visited[i])
////			allVisited = false;
//		cout << visited[i] << ' ';
//	}
//	cout << endl;

	while(!myQ.empty()){
		//cin.get();
		myQ.erase(myQ.begin());
		BFS(myQ[0].second);
//		myQ.erase(myQ.begin());
	}

}

//void AdjMatrixGraph::BFShelper(int vert, vector<pair<int, int>> myQ){

//	if(!visited[vert])
//		cout << cityNames[vert] << ' ';
//
//	visited[vert] = true;
//
//
//	for(int i = 0; i < SIZE; ++i){
//		if(adjMatrix[vert][i] > 1 && !visited[i]){
//			myQ.push_back(make_pair(adjMatrix[vert][i], i));
//			visited[i] = true;
//		}
//	}
//
//	if(!wasSorted){
//		sort(myQ.begin(), myQ.end());
//		wasSorted = true;
//	}
//
//
//	for(int i = 0; i < int(myQ.size()); ++i){
//		cout << cityNames[myQ[i].second] << ' ';
//	}
//
//	while(!myQ.empty()){
//		//cerr << cityNames[myQ[0].second] << ' ';
//		BFShelper(myQ[0].second, myQ);
//		myQ.erase(myQ.begin());
//	}
//}
