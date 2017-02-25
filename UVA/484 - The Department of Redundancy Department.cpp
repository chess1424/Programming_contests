// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=425

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int,int> m;
	vector<int> v;
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(!m[n])v.push_back(n);
		m[n]++;
	}
	for(int i = 0; i < v.size(); i++)
		printf("%d %d\n",v[i],m[v[i]]);
	
	return 0;
}