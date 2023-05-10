
#include "graph.h"


int main()
{
	
	City cse;
	
	cse.loadCity("input.txt");
	cse.printCityGraph();
	cout << "greedy longest road from city 0: ";
	cse.greedyLongestRoad(0);
	cout << endl;
}