#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <string.h>
#include <numeric>

using namespace std;
vector<int> prices(1000);
vector<int> weights(1000);
vector<int> maximal_weight_per_people(100);

vector<int> memo[1000][30];

void clear_memo_vector()
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 30; j++)
			memo[i][j].clear();	
}

int sum_vector_objects_value(vector<int> vector)
{
	int total = 0;
	for (int i = 0; i < (int) vector.size(); i++)
		total += prices[vector[i]];

	return total;
}

vector<int> get_most_valuable_group_objects(int object, int max_weight)
{
	if(object == -1)
		return vector<int>();

	if(!memo[object][max_weight].empty())
		return memo[object][max_weight];

	if(weights[object] > max_weight)
	{
		return get_most_valuable_group_objects(object - 1, max_weight);
	}
		
	vector<int> object_indexes_using_current = get_most_valuable_group_objects(object - 1, max_weight - weights[object]);
	object_indexes_using_current.push_back(object);

	vector<int> object_indexes_not_using_current = get_most_valuable_group_objects(object - 1, max_weight);

	if(sum_vector_objects_value(object_indexes_using_current) > sum_vector_objects_value(object_indexes_not_using_current))
		memo[object][max_weight] = object_indexes_using_current;
	else
		memo[object][max_weight] = object_indexes_not_using_current;

	return memo[object][max_weight];
}


int main()
{
	
	int number_of_objects;
	int number_of_people;
	int number_of_test_cases;
	int total_value;

	cin >> number_of_test_cases;

	for (int i = 0; i < number_of_test_cases; i++)
	{
		cin >> number_of_objects;
		for (int i = 0; i < number_of_objects; i++)
			cin >> prices[i] >> weights[i];

		cin >> number_of_people;
		for (int i = 0; i < number_of_people; i++)
			cin >> maximal_weight_per_people[i];


		for (int i = 0; i < number_of_people; i++)
		{
			vector<int> objects_indexes = get_most_valuable_group_objects(number_of_objects - 1, maximal_weight_per_people[i]);
			total_value += sum_vector_objects_value(objects_indexes);
		}
		
		cout << total_value << '\n';

		prices.clear();
		weights.clear();
		maximal_weight_per_people.clear();
		clear_memo_vector();
		total_value = 0;
	}
}