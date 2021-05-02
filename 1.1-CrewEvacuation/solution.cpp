#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

struct crew_member
{
  string name;
  string type;
  int original_order;
};

bool is_woman_or_child(crew_member member)
{
  return member.type == "woman" || member.type == "child";
}


// Define whitch types of crewe have priority over the others when evacuatig the boat.
bool has_priority_over(crew_member member1, crew_member member2)
{
  if(member2.type == "captain" || member1.type == "rat")
    return false;
  else if(member1.type == "captain" || member2.type == "rat")
    return true;
  else if(is_woman_or_child(member1) && is_woman_or_child(member2))
  {
    // If both have the same priority, get the first to enter the line
    return !(member1.original_order <  member2.original_order);
  }
  else if(is_woman_or_child(member1))
    return false;
  else if(is_woman_or_child(member2))
    return true;
  else
    return false;
}

bool compare(crew_member member1, crew_member member2)
{
  return has_priority_over(member1, member2);
}

void print_evacuation_order(priority_queue<crew_member, std::vector<crew_member>, std::function<bool (crew_member, crew_member)>> queue)
{
  crew_member member;
  while(queue.size())
  {
    member = queue.top();
    queue.pop();
    cout << member.name << "\n";
  }
}

int main()
{
  priority_queue<crew_member, vector<crew_member>, std::function<bool(crew_member, crew_member)>> crew_queue(compare);

  int crew_size;
  crew_member member;
  char crew_name[10];
  char crew_type[10];

  scanf("%d", &crew_size);

  for (int i = 0; i < crew_size; i++)
  {
    scanf("%s %s", crew_name, crew_type);
    member.name = crew_name;
    member.type = crew_type;
    member.original_order = i;

    crew_queue.push(member);
  }

  print_evacuation_order(crew_queue);
}