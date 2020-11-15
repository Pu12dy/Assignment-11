/******************************************************************************
 * AUTHOR        : Jeff Purdy & Breighton Kohl
 * Assignment 11 : BFS & DFS
 * CLASS         : CS1D
 * SECTION       : MW: 2:30PM
 * DUE DATE      : 11/16/2020
 *****************************************************************************/
#include "AdjListGraph.h"

AdjListGraph::AdjListGraph(int numVert) {
	this->numVert = numVert;
	size = 0;
	mileCount = 0;
}

AdjListGraph::~AdjListGraph() {

}

bool AdjListGraph::isFull(){
	return size == numVert;
}

void AdjListGraph::addVertex(int index, string name){
	if(isFull()){
		cout << "Graph is full...\n";
		return;
	}

	Node temp(index, name);
	adjList.push_back(temp);
	size++;
}

void AdjListGraph::addEdge(int originIndex, int destIndex, string destName, int miles){

	Node *temp = new Node(destIndex, destName);
	temp->weight = miles;

	Node* traveler = &adjList[originIndex];

	while(traveler->next != nullptr && traveler->next->weight < miles){
		traveler = traveler->next;
	}

	if(traveler->next != nullptr){
		temp->next = traveler->next;
	}

	traveler->next = temp;

}

void AdjListGraph::DFS(string vert){
	int i = 0;

	while(adjList[i].name != vert){
		++i;
		if (i > 12)
			break;
	}

	bool visisted[numVert];
	for(int i = 0; i < numVert; ++i){
		visisted[i] = false;
	}

	DFShelper(i, visisted);
}

void AdjListGraph::DFShelper(int vert, bool visisted[]){

	visisted[vert] = true;
	cout << adjList[vert].name << " ";

	Node* temp = &adjList[vert];

	while(temp!= nullptr){
		temp = temp->next;
		if(temp != nullptr){
			if(!visisted[temp->index]){
				discoveryEdges.push_back(make_pair(adjList[vert].name, temp->name));
				mileCount += temp->weight;
				DFShelper(temp->index, visisted);
			}
			else{
				bool marked = false;
				for(int i = 0; i < int(discoveryEdges.size()); ++i){
					if(discoveryEdges[i].first  == temp->name
					&& discoveryEdges[i].second == adjList[vert].name){
						marked = true;
						break;
					}
				}
				if(!marked)
					backEdges.push_back(make_pair(adjList[vert].name, temp->name));
			}
		}
	}
}

void AdjListGraph::printVert(int i){
	cout << adjList[i].index << ' '<< adjList[i].name;
}

void AdjListGraph::printVertEdges(int i){
	Node* traversal = &adjList[i];

		while(traversal != nullptr){
			cout << traversal->name << "->";
			traversal = traversal->next;
		}
}

int AdjListGraph::getMiles(){
	return mileCount;
}

void AdjListGraph::printDiscoveryEdges(){
	for(int i = 0; i < int(discoveryEdges.size()); ++i){
		cout << discoveryEdges[i].first << "->"
				<< discoveryEdges[i].second << endl;
	}
}

void AdjListGraph::printBackEdges(){
	for(int i = 0; i < int(backEdges.size()); ++i){
		cout << backEdges[i].first << "->"
				<< backEdges[i].second << endl;
	}
}
