#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string str;
	bool isPanagram, hash[26];;

	getline(cin, str);

	memset(hash, 0, sizeof(hash));

	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z') hash[str[i] - 'a'] = true;
		if(str[i] >= 'A' && str[i] <= 'Z') hash[str[i] - 'A'] = true;
	}

	isPanagram = true;

	for(int i = 0; i < 26; i++)
	{
		if(!hash[i]) 
		{
			isPanagram = false;
			break;
		}
	}

	if(!isPanagram)
		printf("not pangram\n");
	else
		printf("pangram\n");

	return 0;

}