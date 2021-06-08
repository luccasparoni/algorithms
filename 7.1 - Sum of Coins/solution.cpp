#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>

using namespace std;

int number_of_ways_map[1000001];

int get_number_of_ways(vector<int> coins, int desired_sum)
{
	int number_of_ways = 0;

	for (int i = 0; i < (int) coins.size(); i++)
	{
		if (coins[i] < desired_sum)
		{
			if(number_of_ways_map[desired_sum - coins[i]] > 0)
				number_of_ways += number_of_ways_map[desired_sum - coins[i]];
			else
				number_of_ways += get_number_of_ways(coins, desired_sum - coins[i]);
		}
		else if(coins[i] == desired_sum)
		{
			number_of_ways += 1;
		}
	}

	number_of_ways_map[desired_sum] = number_of_ways;

	// cout << number_of_ways << '\n';

	return number_of_ways;
}

int main()
{

	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

	int desired_sum;
	int number_of_coins;
	vector<int> coins;
	int coin_value;

	cin >> number_of_coins >> desired_sum;

	for (int i = 0; i < number_of_coins; i++)
	{
		cin >> coin_value;
		coins.push_back(coin_value);
	}

	for (int i = 0; i < 100; i++)
	{
		cout << number_of_ways_map[i] << '\n';
	}
	

	cout << "\n\n\n" << get_number_of_ways(coins, desired_sum) << "\n\n\n";


    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms";
    return 0;
	
	
}