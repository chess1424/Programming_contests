//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3468&cid=1479

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    string str;
    map<string, int> m;
    while(t--)
    {
    	cin>>str;
    	sort(str.begin(), str.end());
    	if(!m[str]) 
    	{
    		cout<<0<<'\n';
    		m[str] = 1; 
    	}
    	else
    	{
    		cout<<m[str]<<'\n';
    		m[str] +=  1;
    	}
    }
}
