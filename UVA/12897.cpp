#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int t,n;
	char a, b, key, value;
	string str;
	cin >> t;
	while(t--)
	{
		cin>>str;
		cin>>n;

		vector< vector<char> >v(n);

 		for(int i = 0; i < n; i++)
 		{
 			cin>>a>>b;
 			v[i].push_back(b);
 			v[i].push_back(a);
 		}

 		map<char,char> m;
 		for(int i = 0; i < n; i++)
 		{
 			key = v[i][0];
 			value = v[i][1];
	
 			for(int j = 0; j < n; j++)
 				if(v[j][0] == value) 
 					value = v[j][1];
 				
 			m[key] = value;
 		}

 		for(int i = 0; i < str.size(); i++)
 			if(m[str[i]]) str[i] = m[str[i]];

 		cout<<str<<'\n';	
	}
	return 0;
}