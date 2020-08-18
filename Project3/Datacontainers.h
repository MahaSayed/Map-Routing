#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include <map>
#include<ctime>
#include <chrono>

using namespace std;

struct Query
{
	pair <long double, long double> SourceCo_ordinates = make_pair(-1, -1);
	pair <long double, long double> DestinationCo_ordinates = make_pair(-1, -1);
	long double Radius = -1;
}q;

struct Edge
{
	int from, to;
	long double w;

	Edge(int from, int to, long double w) : from(from), to(to), w(w) {} // constructor for initialization

	bool operator < (const Edge & e) const
	{
		return w > e.w;
	}
};

priority_queue <Edge> pq;

vector <pair <int, pair<long double, long double> > > nodes; //nodeId , x y bto3ha
vector <pair <int, long double > > ValidSourceNodes; // node id and its walking time
vector <pair <int, long double > > ValidDestinationNodes;
vector <pair <pair<long double, long double>, pair<long double, long double> > > Edges;   //start , end , dest , speed
map <pair<int, int>, long double> EdgesDist;  //start , end , dest
map <pair<int, int>, long double> EdgesTime;  //start , end , time

vector <Query>  Queries;
vector < vector <pair<long double, long double> > > AdjList(200005);   //x y  llsource w el destination
vector <long double>  Time;    //time[i] = a2al time momkn aro7 beh mn elsource llnode elli elID bta3ha i, i = nodeID  
pair <pair<int, int>, pair<long double, vector<int> > > MiniPath; //(start, end) , (total time, path)
deque <int> BuildingPath;
vector <vector<int>> Paths;
vector <int> path;
vector <vector <long double> > PathsTime;
int ID, R, NumberOfQueries, c, cn;
long double x, y, st, en, sp, dist, DestWalkingTime, MinDestWalkingTime, ToTime, CarTime = 0;


long double CarDist;
long double WalkDist;
long double TotDist;
long double TotTime;