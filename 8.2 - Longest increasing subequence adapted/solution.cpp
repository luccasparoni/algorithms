#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int memo[1001];
int find_greatest_subsequence(int number_of_elephants, vector<int> weights, vector<int> iqs)
{
	int greatest_subsequence_lenght = 1;

	for(int i = 1; i <= number_of_elephants; i++)
	{
		memo[i] = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			int result = memo[j] + 1;
			if(weights[j] < weights[i] && iqs[j] > iqs[i])
				memo[i] = max(result, memo[i]);
		}

		if(greatest_subsequence_lenght < memo[i])
			greatest_subsequence_lenght = memo[i];
	}

	return greatest_subsequence_lenght;
}

int main()
{
	int elephant_weight, elephant_iq;
	vector<int> weights;
	vector<int> iqs;

	memset(memo, -1, sizeof(memo));

	memo[0] = 1;

	while(cin >> elephant_weight >> elephant_iq)
	{
		weights.push_back(elephant_weight);
		iqs.push_back(elephant_iq);
	}

	cout << find_greatest_subsequence((int) weights.size(), weights, iqs);
}