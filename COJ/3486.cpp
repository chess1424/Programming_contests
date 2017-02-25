//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3486&cid=1479

#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,begin,c,t;
    char ch;
    string str;
    
    while(cin >> ch)
    {
    	n = ch - '0';
    	vector< vector<int> > columnas(11, vector<int>(11,0));
	    vector<int> f(10);
	    vector< vector<int> > tablas(4 , vector<int>(11,0));
	    
	    bool correct = true;
	    c = t = 1;
	    
	    ++columnas[c][n];
	    +tablas[t][n];
	    ++f[n];
	    
	    
	    for(int i = 1; i <= 11; i++)
	    {
	    	if(i == 4 || i == 8)
	    	{
	    		cin>>str;
	    		tablas = vector< vector<int> >(4 , vector<int>(11,0));
	    		continue;
	    	}

	    	begin = (i == 1) ? 2 : 1;
	    	c = begin;

	    	for(int j = begin; j <= 11; j++)
	    	{
	    		cin >> ch;
	    		if(ch == '|')
	    		{
	    			t++;
	    			continue;
	    		}
	    		n = ch - '0';

	    		if(++columnas[c++][n] > 1) correct = false;
	    		if(++tablas[t][n] > 1) correct = false;
	    		if(++f[n] > 1) correct = false;
	    	}
	    	
	    	t = c = 1;
	    	f = vector<int>(10);
	    }

	    if(correct)
	    	cout<<"CORRECT"<<'\n';
	    else
	    	cout<<"WRONG"<<'\n';

    }
	return 0;
}