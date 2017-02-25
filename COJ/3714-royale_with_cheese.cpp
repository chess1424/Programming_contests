#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	string str, out, aux;
	int counter;
	while(cin >> str)
	{
		map<char, int>m; 
		counter = 1; out = "";
		for(int i = 0; i < str.length(); i++)
		{
			if(m[str[i]] == 0)
				m[str[i]] = counter++;
		
			aux = to_string(m[str[i]]);
			for(int i = 0; i < aux.length(); i++)
			{
				if(aux[i] == '2') aux[i] = '5';
				else if(aux[i] == '5') aux[i] = '2';
				else if(aux[i] == '6') aux[i] = '9';
				else if(aux[i] == '9') aux[i] = '6';
 			}
			out += aux;
			
		}
		cout << out << '\n';
	}
	return 0;
}