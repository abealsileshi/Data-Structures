#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//add a constructor function to reset after traversing

void Graph::addVertex(string name){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = name;
        vertices.push_back(v);
        //cout << "added: " << v->name << endl;
    }
}



// function to add edge between two vertices
void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                    //cout << "added edge between: " << v1 << " and " << v2 << endl;
                }
            }
        }
    }
}

void Graph::displayEdges(){
     for(int i=0; i < vertices.size(); i++)
    {
        cout << vertices[i]->name << " -> ";
        for(int j =0; j < vertices[i]->adj.size(); j++)
        {
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    
    //first initialize everything as not found
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
    }

    //pointer to sourceVertex
    vertex *vStart;

    for(int i=0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex){
            vStart = vertices[i];
            cout << "Starting vertex (root): " << vStart->name << " -> ";
        }
    }
    
    queue<vertex*> q; 
    
    int level = 1;
    vStart->visited = true;
    q.push(vStart); 
    vertex *n; //pointer to elements in queue
    while(!q.empty()){
       
        n = q.front();
       
        q.pop();
        
        for(int i = 0; i  < n->adj.size(); i++){
               if(!n->adj[i].v->visited){
                  n->adj[i].v->distance = n->distance +1;
                   cout << n->adj[i].v->name <<"(" << n->adj[i].v->distance << ")" << " ";
               
                n->adj[i].v->visited = true;
                q.push(n->adj[i].v);
               }
        }
    }
    cout << endl;
}

void getConnectedComponents(string buildingName, vertex *& node){
    //pointer to sourceVertex
    vertex *vStart;
    vStart = node;

    queue<vertex*> q; 
    
    
    vStart->visited = true;
    q.push(vStart); 
    vertex *n; //pointer to elements in queue
    while(!q.empty()){
       
        n = q.front();
       
        q.pop();
        
        for(int i = 0; i  < n->adj.size(); i++){
               if(!n->adj[i].v->visited){
                 
                   //cout << n->adj[i].v->name <<"(" << n->adj[i].v->distance << ")" << " ";
               
                n->adj[i].v->visited = true;
                q.push(n->adj[i].v);
               }
        }
    }
    cout << endl;
}

int Graph:: getConnectedBuildings(){
    int counter = 0;
    
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->visited == false){
            getConnectedComponents(vertices[i]->name, vertices[i]);
            counter++;
        }
    }
    //cout << "counter value: " <<  counter << endl;
    return counter;
}
