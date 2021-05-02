#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <functional>
#include <iostream>

using namespace std;

stack<char> create_stack_with_input()
{
	string phrase;
	getline(cin, phrase);
	stack<char> phrase_stack;

	for(std::string::iterator it = phrase.begin(); it != phrase.end(); ++it) {
    	phrase_stack.push(*it);
	}

	return phrase_stack;
}

stack<char> remove_consecutive_duplicates(stack<char> stack)
{
	char current_char;
	std::stack<char> cleaned_stack;

	while (stack.size() > 0)
	{
		current_char = stack.top();
		if(cleaned_stack.empty())
		{
			stack.pop();
			cleaned_stack.push(current_char);
			continue;
		}

		if(current_char == cleaned_stack.top())
		{
			cleaned_stack.pop();
		} else
		{
			cleaned_stack.push(current_char);
		}
		stack.pop();
	}

	return cleaned_stack;
}

int main()
{
	stack<char> phrase_stack;

	phrase_stack = create_stack_with_input();

	phrase_stack = remove_consecutive_duplicates(phrase_stack);

	while(!phrase_stack.empty())
	{
		cout << phrase_stack.top();
		phrase_stack.pop();
	}
}

