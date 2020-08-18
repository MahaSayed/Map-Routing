#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include <iomanip>
#include "DataContainers.h"
#include "reading.h"
#include "nodesvalidator.h"
#include "pathing.h"
#include "Distances.h"

using namespace std::chrono;

auto duration_final = 0;
auto final_execution_time = 0;

void writing_inFile()
{
	ofstream myfile;
	myfile.open("Large_OUR_Output.txt", ios::app);
	for (int i = 0; i < BuildingPath.size(); i++)
	{
		myfile << BuildingPath[i] << " ";
	}
	myfile << "\n";
	myfile << fixed << setprecision(2) << TotTime * 60 << " mins \n";
	myfile << fixed << setprecision(2) << TotDist << " km \n";
	myfile << fixed << setprecision(2) << WalkDist*5 << " km \n";
	myfile << fixed << setprecision(2) << CarDist << " km \n\n";

	myfile.close();
}
void write_time()
{
	ofstream myfile;
	myfile.open("Large_OUR_Output.txt", ios::app);
	myfile << duration_final << "\n\n";
	myfile << final_execution_time << "\n";

	myfile.close();
}

int main()
{
	
	auto startProgram = high_resolution_clock::now();
	ReadMapFile("SFMap.txt");
	ReadQueriesFile("SFQueries.txt");
	auto start = high_resolution_clock::now();
	for (int i = 0; i < Queries.size(); i++)
	{
		BuildingPath.clear();
		ValidDestinationNodes.clear();
		ValidSourceNodes.clear();
		pq = priority_queue<Edge>();
		Query q = Queries[i];
		Time.assign(nodes.size()+2, OO);
		NodesValidation(q);
		Dijkstra(); // rage3 mnha elmin path bas // mno hageb elcar distance
		BuildPath(path);
		//////////////////////////////////////////
		 CarDist = CarDistance();
		 WalkDist = WalkingDistance();
		 TotDist = CarDist + WalkDist*5;
		 TotTime = CarTime + WalkDist;
		/////////////////////////////////////////
		/*cout << fixed << setprecision(2) << TotTime*60 << " mins" << endl;
		cout << fixed << setprecision(2) << TotDist << " km" << endl;
		cout << fixed << setprecision(2) << WalkDist*5 << " km" << endl;
		cout << fixed << setprecision(2) << CarDist << " km" << endl;
		for (int i = 0; i < BuildingPath.size(); i++)
		{
			cout << BuildingPath[i] << " ";
		}*/
		cout << endl;
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
		duration_final = duration.count();
		writing_inFile();
		Popato();
	}
	cout << "Execution Time: " << duration_final << " ms" << endl;
	auto endProgram = high_resolution_clock::now();
	auto Tot_duration = duration_cast<milliseconds>(endProgram - startProgram);
	final_execution_time = Tot_duration.count();
	cout << "Total execution time: " << Tot_duration.count()  << " ms"<< endl;
	write_time();
	system("pause");
	return 0;
}