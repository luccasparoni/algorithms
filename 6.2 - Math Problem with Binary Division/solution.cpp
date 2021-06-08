#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define ERROR 0.00000001
#define MIN_INT -100

int p, q, r, s, t, u;

double equation(double x)
{	
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

double find_x_binary(double min_x, double max_x)
{
	double mid;
	double current_result;

	if(max_x - min_x > ERROR)
	{
		mid = (max_x + min_x) / 2;
		current_result =  equation(mid);
		if(current_result <= 0) // real x is smaller
			return find_x_binary(min_x, mid);
		return find_x_binary(mid, max_x);
	} else if(equation(max_x) > ERROR)
	{
		return MIN_INT;
	}
	return max_x;
}


int main()
{
	double max_x = 1;
	double min_x = 0;
	double x;

	while (cin >> p >> q >> r >> s >> t >> u)
	{
		x = find_x_binary(min_x, max_x);
		cout << fixed;
		cout << setprecision(4);

		if(x == MIN_INT)
			cout << "No solution" << '\n';
		else
			cout << round(x * 10000) / 10000 << '\n';
			// cout << x << '\n';
	}
}