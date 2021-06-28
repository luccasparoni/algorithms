#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1000000
// BFS
int find_min_path(vector<vector<int>> connections, vector<int> distance, int target)
{
	queue<int> q;
	q.push(0);
	distance[0] = 1;

	while (!q.empty())
	{
		int computer = q.front(); q.pop();
		for (int i = 0; i < (int) connections[computer].size(); i++)
		{
			int neighbor = connections[computer][i];
			if(neighbor == target)
				return distance[computer] + 1;
			if(distance[neighbor] == INF)
			{
				q.push(neighbor);
				distance[neighbor] = distance[computer] + 1;
			}
		}		
	}	
	
	return INF;
}


int main()
{
	int number_of_computers;
	int number_of_connections;
	int connect_from;
	int connect_to;

	cin >> number_of_computers >> number_of_connections;

	vector<vector<int>> connections(number_of_computers);
	vector<int> computers_distance(number_of_computers, INF);

	for (int i = 0; i < number_of_connections; i++)
	{
		cin >> connect_from >> connect_to;

		connections[connect_from - 1].push_back(connect_to - 1);
		connections[connect_to - 1].push_back(connect_from - 1);
	}

	int result = find_min_path(connections, computers_distance, number_of_computers - 1);	

	if (result == INF)
		cout << "IMPOSSIBLE";
	else
		cout << result;	
}