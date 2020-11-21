#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted
    g.addVertex("AERO");
    g.addVertex("ECON");
    g.addVertex("CHEM");
    g.addVertex("ECOT");
    g.addVertex("HUMN");
    
    g.addEdge("AERO", "ECON");
    g.addEdge("AERO", "CHEM");
    g.addEdge("ECON", "CHEM");
    g.addEdge("AERO", "ECOT");
    g.addEdge("ECOT", "HUMN");
    g.addEdge("CHEM", "HUMN");

    g.addVertex("DUANE"); //Distinct sub-graph
    g.addVertex("BIOCHEM"); //Distinct sub-graph

    g.displayEdges();

    //g.breadthFirstTraverse("HUMN");
    int z = g.getConnectedBuildings();
    cout << "Number of sub-graphs: " << z;
    
    return 0;
}