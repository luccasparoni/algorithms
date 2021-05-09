#include <stdlib.h>
#include <stdio.h>
#include<unordered_set>
#include <iostream>

using namespace std;


int* get_number_as_array(int number_size)
{
  int *number = new int[number_size];
  for (int i = 0; i < number_size; i++)
  {
    scanf("%1d", &number[i]);
  }

  return number;
}

int* get_greatest_number_with_functions(int* number, int* functions, int number_size)
{
  bool started_sequence = false;

  for (int i = 0; i < number_size; i++)
  {
    if(number[i] > functions[number[i]] && started_sequence)
      break;

    if(number[i] <= functions[number[i]] && started_sequence)
      number[i] = functions[number[i]];
    else if(number[i] < functions[number[i]])
    {
      // should only start the sequence if the function returns a
      // stricly GREATER number than the original
      number[i] = functions[number[i]];
      started_sequence = true;
    }
  }

  return number;
}

void print_number(int* number, int number_size)
{
  for (int i = 0; i < number_size; i++)
  {
    cout << number[i];
  }
}

int main()
{
  int number_size;
	cin >> number_size;
  int *number = new int[number_size];
  int functions[9];

  number = get_number_as_array(number_size);

  for (int i = 1; i < 10; i++)
  {
    cin >> functions[i];
  }

  number = get_greatest_number_with_functions(number, functions, number_size);

  print_number(number, number_size);
}