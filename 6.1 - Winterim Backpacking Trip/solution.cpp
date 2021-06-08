#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 1000000000

int nights_needed_to_complete(vector<int> campsites_distances, int walk_distance) //(6)
{
	int walked_distance = 0; // 24
	int remaining_walk = walk_distance;
	int total_nights = 0; // 2


	for (int i = 0; i < (int) campsites_distances.size(); i++)
	{
		int diff = campsites_distances[i] - walked_distance;
		if(diff > walk_distance) return MAX_INT; // cannot walk to the next campsite

		if(i == (int) campsites_distances.size())  // got in the final campiste
			return total_nights;
		else if(diff <= walk_distance) // can walk to the next compsite
		{
			if(remaining_walk >= diff) // does not need to sleep here
				remaining_walk -= diff;
			else{ // need to sleep here and restart the walk
				remaining_walk = walk_distance - diff;
				total_nights += 1;
			}
			walked_distance += diff;	 // walksto the next campiste			
		}
	}
	return total_nights;
}

int find_max_walk(int trip_duration, vector<int> campsites_distances, int min_possible_distance, int max_possible_distance)
{
	if(min_possible_distance == max_possible_distance)
	{
		if(nights_needed_to_complete(campsites_distances, min_possible_distance) != trip_duration)
			return MAX_INT;
		return min_possible_distance;
	}

	int mid_distance = (max_possible_distance + min_possible_distance) / 2;

	int nights_needed = nights_needed_to_complete(campsites_distances, mid_distance);

	if(nights_needed > trip_duration)
		return find_max_walk(trip_duration, campsites_distances, mid_distance + 1, max_possible_distance);
	// real distance is greater than hipothesis
		
	// real distance CAN BE smaller than hipothesis;
	return min(find_max_walk(trip_duration, campsites_distances, min_possible_distance, mid_distance), mid_distance);
}


int main()
{
	int number_of_campsites;
	int trip_duration;
	int distance;
	int max_walk;
	int total_distance = 0;
	vector<int> campsites_distances;

	while(cin >> number_of_campsites >> trip_duration)
	{
		for (int i = 0; i < number_of_campsites+1; i++)
		{
			cin >> distance;
			total_distance += distance;
			campsites_distances.push_back(total_distance);
		}

		max_walk = find_max_walk(trip_duration, campsites_distances, 0, total_distance);

		cout << max_walk << '\n';

		campsites_distances.clear();
		total_distance = 0;
	}
}