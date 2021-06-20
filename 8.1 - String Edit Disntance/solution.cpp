#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Globally declared to avoid passing as arguments
string word1;
string word2;

int memo[5001][5001];

int get_min(int a, int b, int c)
{
	return min(min((a), (b)), (c));
}

int find_edit_distance(int n, int m)
{
	if(memo[n][m] != -1)
		return memo[n][m];

	if(n == 0)
	{
		memo[n][m] = m;
		return m;
	}
	if(m == 0)
	{
		memo[n][m] = n;
		return n;
	}

	int cost;	
	if(word1[n - 1] == word2[m - 1])
		cost = 0;
	else 
		cost = 1;

	memo[n][m] = get_min(cost + find_edit_distance(n - 1, m - 1), 
		1 + find_edit_distance(n, m - 1), // remove one letter
		1 + find_edit_distance(n - 1, m)); // add one letter  
	
	return memo[n][m];	
}

int main()
{

	memset(memo, -1, sizeof(memo));
	cin >> word1 >> word2;

	cout << find_edit_distance(word1.size(), word2.size());	
}