
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class City{
	
	private:
	int * * distanceGraph;
	int numberOfCity;
	void createCityGraph();
	
	
	public:
	
	void loadCity(string file);
	void printCityGraph();
	void greedyLongestRoad(int city);
};


void City::createCityGraph()
{
	// square matrix
	distanceGraph = new int*[numberOfCity];
	for(int i = 0; i < numberOfCity; i++)
		distanceGraph[i] = new int [numberOfCity];
	for(int i = 0; i < numberOfCity; i++) {
		for(int j = 0; j < numberOfCity; j++) {
			distanceGraph[i][j] = 0;
		}
	}
}

void City::printCityGraph()
{
	cout << endl << "city\t";
	for(int i = 0; i < numberOfCity; i++) 
		cout << i << '\t';
	
	cout << endl;
	
	for(int i = 0; i < numberOfCity + 1; i++) 
		cout << '-' << '\t';
	
	cout << endl;

	for(int i = 0; i < numberOfCity; i++) {
		cout << i << '\t';
		
		for(int j = 0; j < numberOfCity; j++)
			cout << distanceGraph[i][j] << '\t';
		
		cout << endl;
	}
	cout << "------------------------------------------------" << endl;
}


void City::greedyLongestRoad(int city)
{
	static int citiesVisited[20] = {0};
	citiesVisited[city] = 1;
	// 1 for visited, 0 for unvisited
	
	int maxDistance = 0, tempCity;
	
	for(int i = 0; i < numberOfCity; i++) {
		if(!citiesVisited[i] && (distanceGraph[city][i] > maxDistance)) { // do not visit previously visited or current cities
			tempCity = i;
			maxDistance = distanceGraph[city][i];
		}
	}
	
	if(maxDistance) { // don't iterate the recursion if the distance is 0
		cout << tempCity << ' ';
		City::greedyLongestRoad(tempCity);
	}
}

void City::loadCity(const string filename)
{
	ifstream file;
	file.open(filename.c_str());
	int city1,city2,distance;

	file>>numberOfCity;
	createCityGraph();

	while(file>>city1)
	{
		file>>city2;
		file>>distance;
		distanceGraph[city1][city2] = distance;
	}
	file.close();
}






