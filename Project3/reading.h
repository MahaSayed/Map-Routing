#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
#include "DataContainers.h"

using namespace std;


void ReadQueriesFile(string FileName) {
	string line;
	ifstream fi;
	fi.open(FileName);

	if (fi.is_open()) {

		fi >> NumberOfQueries;
		//cout << "Q: " << NumberOfQueries << endl;
		while (NumberOfQueries--) {

			fi >> x;   fi >> y;
			q.SourceCo_ordinates = make_pair(x, y);

			//cout << "file: " << NumberOfQueries << " " << x  << " " << y;
			//cout << endl;
			fi >> x;   fi >> y;
			q.DestinationCo_ordinates = make_pair(x, y);

			fi >> R;
			long double af = 1000;
			q.Radius = R / af;

			Queries.push_back(q);
		}
	}
	fi.close();
}



void ReadMapFile(string FileName)
{

	ifstream fin;
	fin.open(FileName);
	bool open = true;
	open = fin.is_open();
	if (open)
	{
		fin >> c;
		//cout << "MapFile: " << c << endl;
		while (c--)
		{
			fin >> ID;   fin >> x;   fin >> y;
			pair <long double, long double> p = { x, y };
			nodes.push_back({ ID, p });
		}
		fin >> cn;
		while (cn--)
		{
			fin >> st;     fin >> en;
			fin >> dist;   fin >> sp;
			Edges.push_back({ { st, en },{ dist, sp } });
			EdgesDist[{st, en}] = dist;
			EdgesDist[{en, st}] = dist;
			EdgesTime[{st, en}] = dist / sp;
			EdgesTime[{en, st}] = dist / sp;
			AdjList[st].push_back({ en, (dist / sp) });
			AdjList[en].push_back({ st, (dist / sp) });
		}

	}
	fin.close();
}