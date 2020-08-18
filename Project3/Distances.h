#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include "Datacontainers.h"

#define Speed 1.38889

using namespace std;

long double CarDistance()
{
	long double CarDist = 0;
	CarTime = 0;
	for (int i = 0; i < BuildingPath.size() - 1; i++)
	{
		CarDist += EdgesDist[{BuildingPath[i], BuildingPath[i + 1]}];
		CarTime += (EdgesTime[{BuildingPath[i], BuildingPath[i + 1]}]);
	}
	return CarDist;
}


long double WalkingDistance()
{
	long double t;
	//cout << "Path start node: " << BuildingPath[0] << "  " << ValidSourceNodes[BuildingPath[0]].second << endl;
	t = ValidSourceNodes[BuildingPath[0]].second;
	t += ValidDestinationNodes[BuildingPath[BuildingPath.size()-1]].second;
	//cout << "Path end node: " << BuildingPath[BuildingPath.size()-1] << "  " << ValidDestinationNodes[BuildingPath[BuildingPath.size() - 1]].second << endl;
	return t;
}