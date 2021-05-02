#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

struct argus_register
{
  int id;
  int period;
  int next_execution;
};

bool compare(argus_register reg1, argus_register reg2)
{
  if(reg1.next_execution == reg2.next_execution)
    return reg1.id > reg2.id;
  return reg1.next_execution > reg2.next_execution;
}

void print_queries(priority_queue<
    argus_register, 
    vector<argus_register>, 
    std::function<bool(argus_register, argus_register)>> queue, int number_of_queries)
{
  argus_register current_register;
  for (int i = 0; i < number_of_queries; i++)
  {
    current_register = queue.top();
    
    queue.pop();
    cout << current_register.id << '\n';

    current_register.next_execution += current_register.period;
    queue.push(current_register);
  }
}

int main()
{
  priority_queue<
    argus_register, 
    vector<argus_register>, 
    std::function<bool(argus_register, argus_register)>> register_queue(compare);

  string input;
  argus_register current_register;
  int number_of_queries;


  while(std::getline (std::cin,input) && !input.empty() && input[0] != '#')
  {
    sscanf(input.c_str(), "Register %d %d", &current_register.id, &current_register.period);
    current_register.next_execution = current_register.period;

    register_queue.push(current_register);
  }

  scanf("%d", &number_of_queries);

  print_queries(register_queue, number_of_queries);
}