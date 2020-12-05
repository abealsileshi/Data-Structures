#include <stdio.h>
#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;


int main() {
		Graph g1;
		g1.insertVertex(10);
		g1.insertVertex(12);
		g1.insertVertex(13);
		g1.insertEdge(10, 12);
		g1.insertEdge(10, 13);
		g1.insertEdge(13, 10);

		if(g1.detectCycle(10)) 
			cout<< "Test Case1 Passed\n";
		else
			cout<<"Test Case1 Failed\n";


		cout << endl;


		Graph g2; //second test case
		g2.insertVertex(1);
		g2.insertVertex(2);
		g2.insertVertex(3);
		g2.insertVertex(4);
		g2.insertVertex(5);

		g2.insertEdge(1, 2);
		g2.insertEdge(1, 1); //here 1 loops to itsself
		g2.insertEdge(2, 4);
		g2.insertEdge(3, 4);
		g2.insertEdge(3, 5);
		g2.insertEdge(3, 2);
		
		if(g2.detectCycle(1))
			cout<< "Test Case2 Passed\n";
		else
			cout<<"Test Case2 Failed\n";



		/* Types of loops
		1) A node can loop to itself
		2) A node is looping in a couple
		3) A node is looping in more than couple
		4) There is a loop within a loop
		*/

	return 0;
}
