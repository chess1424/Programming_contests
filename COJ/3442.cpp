//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3442&cid=1479

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str,aux;
    int l,r,med;
    while(cin >> str)
    {

    	if(str.length() % 2 == 0) cout<<"error"<<'\n';
    	else
    	{
    		aux = str;
    		cout<<str<<'\n';
    		med = str.length() / 2;
    		l = r = med;
    		for(int i = 1; i <= med; i++)
    		{
    			str[l--] = ' ';
    			str[r++] = ' ';
    			cout<<str<<'\n';
    		}
    		l++;
    		r--;
    		for(int i = med+1; i <= str.length() - 1; i++)
    		{
    			str[l] = aux[l++];
    			str[r] = aux[r--];
    			cout<<str<<'\n';
    			
    		}
    	}
    }
	return 0;
}
