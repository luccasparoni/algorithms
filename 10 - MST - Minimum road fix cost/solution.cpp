#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <functional>
#include <chrono>

using namespace std;
typedef pair<int, int> city_connection;

bool compare(city_connection city_a, city_connection city_b)
{
	return city_a.second > city_b.second; // compare connection road sizes
}

double minimum_repair_cost(vector<vector<city_connection>> cities_connections, vector<int> visited)
{
	priority_queue<
		city_connection,
		vector<city_connection>, 
		function<bool(city_connection, city_connection)>> queue(compare);


	auto process_city = [&](city_connection city)
	{
		for (int i = 0; i < (int) cities_connections[city.first].size(); i++)
		{
			city_connection neighbor_city = cities_connections[city.first][i];
			if(visited[neighbor_city.first] == 0)
			{
				queue.push(neighbor_city);
			}
		}		
	};

	double minimum_cost = 0;

	visited[0] = 1;
	process_city(city_connection(0, 0));
	
	while (!queue.empty())
	{
		city_connection city = queue.top(); queue.pop();

		if(visited[city.first] == 0)
		{
			visited[city.first] = 1;
			minimum_cost += city.second;

			process_city(city);
		}
	}

	for (int i = 0; i < (int) visited.size(); i++)
	{
		if(visited[i] == 0)
			return -1;
	}
	return minimum_cost;
}

int main()
{
	int number_of_cities;
	int number_of_roads;
	int connect_from;
	int connect_to;
	int road_size;

	cin >> number_of_cities >> number_of_roads;
	vector<vector<city_connection>> cities_connections(number_of_cities);
	vector<int> visited(number_of_cities, 0);


	for (int i = 0; i < number_of_roads; i++)
	{
		cin >> connect_from >> connect_to >> road_size;

		cities_connections[connect_from - 1].push_back(city_connection(connect_to - 1, road_size));
		cities_connections[connect_to - 1].push_back(city_connection(connect_from - 1, road_size));
	}

	double cost = minimum_repair_cost(cities_connections, visited);

	if (cost == -1)
	{
		cout << "IMPOSSIBLE";
	}else 
		printf("%.0lf", cost);

    return 0;	
}