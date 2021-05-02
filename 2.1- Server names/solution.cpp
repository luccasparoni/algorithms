#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

string remove_last_char(char *string)
{
	std::string temp(string);
	return temp.substr(0, temp.length()-1);
}

int main()
{	
	int m, n;

	char server_name[12];
	char server_ip[16];
	char command[12];
	char server_ip_with_comma[20];
	memset(server_ip_with_comma, 0x00, 25);
	string server_ip_without_comma;


	scanf("%d %d", &n, &m);

	unordered_map<string, string> server_names;

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", server_name, server_ip);
		server_names[server_ip] = server_name;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s %s", command, server_ip_with_comma);

		server_ip_without_comma = remove_last_char(server_ip_with_comma);
		
		cout << command << " " << server_ip_without_comma << "; #" << server_names[server_ip_without_comma] << endl;
	}
}