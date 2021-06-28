#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
// BFS
int count_nodes_in_the_group(vector<vector<int>> connections, vector<int> visited, int first_node)
{
	queue<int> q;
	int total_nodes = 1;
	q.push(first_node);
	visited[first_node] = 1;

	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (int i = 0; i < (int) connections[node].size(); i++)
		{
			int neighbor = connections[node][i];
			if(visited[neighbor] == 0)
			{
				q.push(neighbor);
				visited[neighbor] = 1;
        		total_nodes += 1;
			}
		}		
	}	
	
	return total_nodes;
}


int main()
{
	int number_of_nodes;
	int number_of_groups;
	int connect_from;
	int connect_to;
	int group_size;

	cin >> number_of_nodes >> number_of_groups;

	vector<vector<int>> connections(number_of_nodes);
	vector<int> visited(number_of_nodes, 0);

	for (int i = 0; i < number_of_groups; i++)
	{
		cin >> group_size;
		if(group_size > 0)
			cin >> connect_from;

		for (int j = 1; j < group_size; j++)
		{
			cin >> connect_to;		
			connections[connect_from - 1].push_back(connect_to - 1);
			connections[connect_to - 1].push_back(connect_from - 1);
		}
	}

	for (int target = 0; target < number_of_nodes; target++)
	{	
		printf("%d ", count_nodes_in_the_group(connections, visited, target));	
		std::fill(visited.begin(), visited.end(), 0);
	}
}