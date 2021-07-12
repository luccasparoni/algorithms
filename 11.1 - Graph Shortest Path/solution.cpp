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
typedef pair<int, int> flight_route;

bool compare(flight_route city_a, flight_route city_b)
{
	return city_a.second < city_b.second; // compare flights lengths
}

vector<double> shortest_routes_from(vector<vector<flight_route>> flights, vector<double> distances, int first_city)
{
	priority_queue<
		flight_route,
		vector<flight_route>, 
		function<bool(flight_route, flight_route)>> queue(compare);

	queue.push(flight_route(first_city - 1, 0));
	distances[first_city - 1] = 0;	

	while (!queue.empty())
	{
		flight_route route = queue.top(); queue.pop();

		if(route.second > distances[route.first])
			continue;
		for (int i = 0; i < (int) flights[route.first].size(); i++)
		{
			flight_route flight = flights[route.first][i];
			if(distances[flight.first] == -1 || distances[flight.first] > distances[route.first] + flight.second)
			{
				distances[flight.first] = distances[route.first] + flight.second;
				queue.push(flight);			
			}
		}
	}

	return distances;
}

int main()
{
	int number_of_cities;
	int number_of_flights;
	int flight_from;
	int flight_to;
	int flight_length;

	cin >> number_of_cities >> number_of_flights;

	vector<vector<flight_route>> flights(number_of_cities);

	vector<double> distances(number_of_cities, -1);


	for (int i = 0; i < number_of_flights; i++)
	{
		cin >> flight_from >> flight_to >> flight_length;

		flights[flight_from - 1].push_back(flight_route(flight_to - 1, flight_length));
	}

	vector<double> shortest_routes = shortest_routes_from(flights, distances, 1);

	for (int i = 0; i < number_of_cities; i++)
	{
		printf("%.lf ", shortest_routes[i]);
	}

    return 0;	
}