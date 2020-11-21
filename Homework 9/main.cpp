#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

    
int main()
{
    Graph g; // undirected and unweighted
    g.insertVertex("0");
    g.insertVertex("1");
    g.insertVertex("2");
    g.insertVertex("3");
    g.insertVertex("4");
    g.insertVertex("5");
    g.insertVertex("6");
    g.insertVertex("7");
    
    g.createEdge("1", "0", 10);
    g.createEdge("0", "6", 6);
    g.createEdge("1", "3", 2);
    g.createEdge("1", "4", 5);
    g.createEdge("1", "6", 1);
    g.createEdge("5", "1", 6);
    g.createEdge("0", "2", 7);
    g.createEdge("0", "3", 6);
    g.createEdge("2", "3", 7);
    g.createEdge("3", "4", 6);
    g.createEdge("5", "4", 6);
    g.createEdge("5", "6", 6);
    g.createEdge("5", "7", 6);


  //  g.displayEdges();

    cout<< endl;
    cout<< endl;
    cout<< endl;
    cout<< endl;

    g.setAllVerticesDefault();

    g.depthFirstTraversal("4");

    g.setAllVerticesDefault();

    cout<< endl;
    cout<< endl;

   // cout << "Problem 3: TRAVERSE WITH DIJSKTRA'S" << endl;

   // g.traverseWithDijkstra("AERO");
    
   // g.setAllVerticesDefault();

  //  cout << "Problem 4: MinDist Path" << endl;


  //  g.minDistPath("ECOT", "ECON");

    return 0;
}