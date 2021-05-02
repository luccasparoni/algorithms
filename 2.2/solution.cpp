#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
	string phrase;
	getline(cin, phrase);
	stack<char> initial_phrase;
	stack<char> cleaned_phrase;
	char current_char;

	for(std::string::iterator it = phrase.begin(); it != phrase.end(); ++it) {
    	initial_phrase.push(*it);
	}

	while (initial_phrase.size() > 0)
	{
		if(cleaned_phrase.empty())
		{
			current_char = initial_phrase.top();
			initial_phrase.pop();
			cleaned_phrase.push(current_char);
			continue;
		}

		current_char = cleaned_phrase.top();

		if(current_char == initial_phrase.top())
		{
			cleaned_phrase.pop();
		} else
		{
			cleaned_phrase.push(initial_phrase.top());
		}
		initial_phrase.pop();
	}

	while(!cleaned_phrase.empty())
	{
		cout << cleaned_phrase.top();
		cleaned_phrase.pop();
	}
}

// reallaz
// y

