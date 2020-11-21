#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

using namespace std;

struct vertex;
struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    vertex() {
        this->visited = false;
        this->distance = 0;
        this->pred = NULL;
    }
    string name;
    bool visited;
    int distance;
    vertex *pred;
    vector<adjVertex> adj;
};

class Graph
{
    public:
        void setAllVerticesDefault();
        void createEdge(string v1, string v2, int num);
        void insertVertex(string name);
        void displayEdges();

        void depthFirstTraversal(string sourceVertex);
        void traverseWithDijkstra(string sourceVertex);
        void minDistPath(string start, string end);
      
    private:
        vector<vertex*> vertices;
};

#endif // GRAPH_H
