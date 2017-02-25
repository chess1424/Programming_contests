// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2261

#include <bits/stdc++.h>
using namespace std;

string vectorToString(vector<int> v)
{
	string out = "";
	for(int i = 0; i < v.size(); i++)
		out = out + to_string(v[i]) + " ";
	return out;
}
int main(int argc, char const *argv[])
{
    int n, groups, maxNum, num;
    string str;
    vector<int> v(5);

    while(scanf("%d",&n) && n)
    {
    	map<string,int> m;
    	map<string,int>::iterator it;
    	
    	for(int i = 0; i < n; i++)
    	{	
    		for(int j = 0; j < 5; j++)
    			scanf("%d",&v[j]);
    		sort(v.begin(),v.end());
    		m[vectorToString(v)]++;
    	}
    	

    	groups = 0;
    	maxNum = 0;
    	
    	for(it = m.begin(); it != m.end(); ++it)
    	{
    		if(it->second > maxNum){ groups = 1; maxNum = it->second; }
    		else if(it->second == maxNum ){ groups++; }
    	}
    	
    	printf("%d\n",maxNum * groups);

    }


    return 0;
}
