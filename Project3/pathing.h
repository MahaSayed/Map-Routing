#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include "DataContainers.h"
#include "NodesValidator.h"

using namespace std;

#define OO 100000009


void Dijkstra()
{
	path = vector <int>(nodes.size() + 2, -1);
	while (!pq.empty())
	{
		Edge e = pq.top();
		pq.pop();
		if (e.w <= Time[e.to])  // HAMDY BY2OL NSHEEL = DI 3SHAN HTFRE2 AWY FL TIME....
		{
			path[e.to] = e.from;
			for (int i = 0; i < AdjList[e.to].size(); i++)
			{
				Edge ne = Edge(e.to, AdjList[e.to][i].first, AdjList[e.to][i].second);
				if (Time[ne.to] > Time[ne.from] + ne.w)
				{
					Time[ne.to] = ne.w = Time[ne.from] + ne.w;
					pq.push(ne);
				}
			}
		}
	}
}


//
void BuildPath(vector <int> path)
{//hamsek akher node fe elpath w abtedi atla3
	int End = path[path.size() - 2];
	int End1 = End;
	while (path[End] != -1)
	{
		BuildingPath.push_front(path[End]);
		End = path[End];
	}
	BuildingPath.push_back(End1);
}

void Popato()
{
	//AdjList[nodes.size()].clear;
	for (int i = 0; i < AdjList.size(); i++)
	{
		if (AdjList[i].size()) {
			pair<long double, long double> p = AdjList[i][AdjList[i].size() - 1];
			if (p.first == nodes.size())
			{
				AdjList[i].pop_back();
			}
		}
	}
}