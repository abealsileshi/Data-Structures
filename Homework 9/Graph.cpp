#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

void Graph::createEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.weight = num;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.weight = num;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                    //cout << "added edge between: " << v1 << " and " << v2 << endl;
                }
            }
        }
    }
}

void Graph::insertVertex(string name){
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

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}


void DFShelper(vertex * node){
  node->visited = true;
    for(int x = 0; x < node->adj.size(); x++){
        if(!node->adj[x].v->visited){
            DFShelper(node->adj[x].v);
        }
    }
    cout << node->name << " -> ";
    
}


void Graph::depthFirstTraversal(string sourceVertex)
{
    vertex * ptr;//points to our source vertex
    for(int i = 0; i < vertices.size(); i++){ //finding our source vertex
        if(vertices[i]->name == sourceVertex){
            ptr = vertices[i];
        }
    }
    DFShelper(ptr);
    cout << "DONE" << endl;
  
}


void Graph::traverseWithDijkstra(string start)
{
    vertex * source;//points to our source vertex
    for(int i = 0; i < vertices.size(); i++){ //finding our source vertex
        if(vertices[i]->name == start){
            source = vertices[i];
        }
    }
    source->visited = true;
    vector<vertex*> solved; //solved vertices
    solved.push_back(source);
    
    while(solved.size() != vertices.size()){
        int minDist = 9999;
        vertex * s = NULL; //points to vertices in the solved vector
        vertex * solV = NULL; //points to the adjacent 
        vertex * temp = NULL; //stores pred node
        
        for(int i = 0; i < solved.size(); i++){
            s = solved[i];
            for(int x = 0; x < s->adj.size(); x++){
                if(!s->adj[x].v->visited){
                     int endDist = s->distance + s->adj[x].weight;
                        if(endDist < minDist){
                            solV = s->adj[x].v;
                            minDist = endDist;
                            temp = s;
                        }
                }
            }
        }
        solV->pred = temp;
        solV->distance = minDist;
        solV->visited = true;
        solved.push_back(solV);        
    }
}



void Graph::minDistPath(string source, string destination)
{
    traverseWithDijkstra(source);
    vertex * dest;
    for(int i = 0; i < vertices.size(); i++){ //finding our destination vertex
        if(vertices[i]->name == destination){
            dest = vertices[i];
        }
    }
    int distance = dest->distance;
     vector <string> path;
    while(dest->name != source){
       path.push_back(dest->name);
        dest = dest->pred;
    }
    path.push_back(dest->name);
    for(int x = path.size() - 1; x > -1; x--){ 
      cout << path[x] << " -> ";
    }
    cout << "DONE " << "[" << distance << "]";
    cout << endl;
}




void Graph::setAllVerticesDefault()
{
  int i;
  for(i=0; i<vertices.size(); i++) {
      vertices[i]->visited = false;
      vertices[i]->distance = 0;
  }
}


//draft version
// void Graph::traverseWithDijkstra(string start)
// {
//     vertex * source;//points to our source vertex
//     for(int i = 0; i < vertices.size(); i++){ //finding our source vertex
//         if(vertices[i]->name == start){
//             source = vertices[i];
//         }
//     }
//     source->visited = true;
//     vector<vertex*> solved; //solved vertices
//     solved.push_back(source);
   
//     while(solved.size() != vertices.size()){
//         int minDist = 9999;
//         vertex * s = NULL; //points to vertices in the solved vector
//         vertex * solV = NULL; //points to the adjacent 
        
//         for(int i = 0; i < solved.size(); i++){
//             s = solved[i];
//             for(int x = 0; x < s->adj.size(); x++){
//                 if(!s->adj[x].v->visited){
//                      s->adj[x].v->distance = s->distance + s->adj[x].weight;
//                         if(s->adj[x].v->distance < minDist){
//                             solV = s->adj[x].v;
//                             minDist = s->adj[x].v->distance;
//                             solV->pred = s;
//                         }
//                 }
//             }
//         }
//         solV->visited = true;
//         solved.push_back(solV);
//     }
// }