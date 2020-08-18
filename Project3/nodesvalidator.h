#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include "DataContainers.h"


using namespace std;

#define OO 100000009

void memPathTime() {
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			PathsTime[i][j] = OO;
		}
	}
}

void NodesValidation(Query q) { //btsave eltime bsecond ba2et min
	ValidDestinationNodes.resize(nodes.size() + 1);
	ValidSourceNodes.resize(nodes.size() + 1);
	for (int i = 0; i < nodes.size(); i++) {
		long double xs = abs(nodes[i].second.first - q.SourceCo_ordinates.first);
		xs *= xs;
		long double ys = abs(nodes[i].second.second - q.SourceCo_ordinates.second);
		ys *= ys;
		long double Sradius = sqrt(xs + ys);

		if (Sradius <= q.Radius)
		{
			long double WalkingTime = Sradius / 5;
			ValidSourceNodes[nodes[i].first] = make_pair( nodes[i].first, WalkingTime );
			//cout << nodes[i].first << "   ***" << WalkingTime << endl;
			Edge e = Edge(-1, nodes[i].first, WalkingTime);
			Time[nodes[i].first] = WalkingTime;
			pq.push(e);
		}


		long double xd = abs(nodes[i].second.first - q.DestinationCo_ordinates.first);
		xd *= xd;
		long double yd = abs(nodes[i].second.second - q.DestinationCo_ordinates.second);
		yd *= yd;
		long double Dradius = sqrt(xd + yd);

		if (Dradius <= q.Radius)
		{
			long double WalkingTime = Dradius / 5;
			//cout << nodes[i].first << "   **" << WalkingTime << endl;
			ValidDestinationNodes[nodes[i].first] = make_pair( nodes[i].first, WalkingTime );
			AdjList[nodes.size()].push_back({ nodes[i].first, WalkingTime });
			AdjList[nodes[i].first].push_back({ nodes.size(), WalkingTime });
		}
	}
}