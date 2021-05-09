#include <stdlib.h>
#include <stdio.h>
#include<unordered_set>
#include <iostream>

using namespace std;


int main()
{
	unordered_set<int> badges;
	int number_of_badges;
	int badge_coolnes;
	cin >> number_of_badges;
	int coins_needed = 0;

	for (int i = 0; i < number_of_badges; i++)
	{
		cin >> badge_coolnes;
		if(badges.find(badge_coolnes) != badges.end()) // found the same badge
		{
			while(badges.find(badge_coolnes) != badges.end())
			{
				badge_coolnes++;
				coins_needed++;
			}
		}
		badges.insert(badge_coolnes);
	}

	cout << coins_needed;
}