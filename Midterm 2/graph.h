#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct adjVertex;

struct Vertex {
	int key;
	bool visited;
	int distance;
	vector<adjVertex> adjList;
};

struct adjVertex {
	Vertex* v;
};

class Graph {
public:
	vector<Vertex*> vertices;
	Vertex* search(int k);

	int insertVertex(int k);
 	int insertEdge(int start, int end);
	bool detectCycle(int k);
};
