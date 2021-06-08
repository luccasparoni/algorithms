#include <stdlib.h>
#include <stdio.h>
#include<unordered_set>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> possible_permutations(vector<int> numbers, int index)
{
	vector<vector<int>> permutations;
	vector<int> current;
	
	if(numbers.size() == index)
	{
		current.push_back(numbers[index]);
		permutations.push_back(current);
		return permutations;
	}

	permutations = possible_permutations(numbers, index+1);

	for(vector<int> v : permutations)
	{
		// current.clear();
		current = v;
		current.push_back(numbers[index]);
		cout << "'oi'" << '\n';
		// permutations.push_back(current);
	}
	current.clear();
	current.push_back(numbers[index]);
	permutations.push_back(current);

	return permutations;	
}


int main()
{
	int desired_sum;
	int array_size;
	int input;
	vector<int> numbers;

	cin >> desired_sum;
	cin >> array_size;

	for (int i = 0; i < array_size; i++)
	{
		cin >> input;
		numbers.push_back(input);
	}	
	
	auto permutations = possible_permutations(numbers, 0);

	// for(auto v : permutations)
	// 	for(auto e : v)
	// 		cout << e << '\n';

	// int *permutations_with_desired_sum = find_permutations_that_have_sum(permutations, desired_sum);

	// cout << permutations;
}