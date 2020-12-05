#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int Graph::insertVertex(int k) {
	Vertex* newVertex = new Vertex;
	newVertex->key = k;
	vertices.push_back(newVertex);
	return 0;
}

int Graph::insertEdge(int start, int end) {
	adjVertex* newEdge = new adjVertex;
	for (unsigned int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == start) { // find start @ index 'i'
			for (unsigned int j=0; j<vertices.size(); j++) {
				if (vertices[j]->key == end) { // find end @ index 'j'
					newEdge->v = vertices[j];
					vertices[i]->adjList.push_back(*newEdge);
					return 0;
				}
			}
			cout << "End node not found :(\n";
			return -1;
		}
	}
	cout << "Start node not found :(\n";
	return -1;
	//newEdge->v = ??; // Vertex reference containing the 'end' value;
}

Vertex* Graph::search(int k) {
	for (unsigned int i=0; i<vertices.size(); i++) {
		if (vertices[i]->key == k) {
			//cout << "Found it!\n";
			return vertices[i];
		}
	}
	cout << "Didn't find the key :(\n";
	return NULL;
}

bool flag = false; // true if there's a cycle

void DFShelper(Vertex * node, vector <Vertex *> &visited){
  node->visited = true;
    for(int x = 0; x < node->adjList.size(); x++){
        if(!node->adjList[x].v->visited){
			visited.push_back(node->adjList[x].v);
			for(int i = 0; i < node->adjList.size(); i++){
				if(node->adjList[i].v->key == node->key){ //checking if a node loops to itself
					//cout << "here (1)" << endl;
					flag = true;
				}
			}
			//for(int t = 0; t < node->adjList.size(); t++){
				for(int f = 0; f < node->adjList[x].v->adjList.size(); f++){ //checking if any of the adjacent vertices have an adjacent vertice which is the original vertex we started with
					if(node->key == node->adjList[x].v->adjList[f].v->key){ 
						flag = true;
						//cout << "here (2)" << endl;
					}
				}
			//}
            DFShelper(node->adjList[x].v, visited);
        }

    }
    cout << node->key << " -> ";
}

// bool detectCycleHelper(Vertex * node, int size){
// 	return true; 
// }

bool Graph::detectCycle(int k) {
	Vertex* startV = search(k);
	//int size = vertices.size(); //size of our graph
	//int counter = 0; //counter to count how many nodes we've visited
	vector <Vertex *> visited; //don't end up using this
	visited.push_back(startV);

	cout << "Adjacent list to our starting vertex" << endl; //useful visualization
	for(int z = 0; z < startV->adjList.size(); z++){
				cout << startV->adjList[z].v->key << " ";
	}
	cout << endl;



	DFShelper(startV, visited);
	cout << endl;

	cout << "After DFS traversal, here's what's in the visited vector " << endl; //didn't end up utilizing visited vector, ran outta time
	for(int i = 0; i < visited.size(); i++){
		cout << visited[i]->key << " , ";
	}
	cout << endl;
	//detectCycleHelper(startV, size);
	//cout << "bool flag is " << flag << endl;
	if(flag == true){
		return true;
	}
	return false;
}
