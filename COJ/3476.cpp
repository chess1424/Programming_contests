//Martinez Ojeda Carlos Roberto
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3476&cid=1479

#include <bits/stdc++.h>
#define MOD 1000000007;
using namespace std;

long long max(long long a, long long b){ return (a > b) ? a : b;}
long long min(long long a, long long b){ return (a < b) ? a : b;}

long long factorial(long long n)
{
	long long out = 1;

	for(long long i = 1; i <= n; i++)
		out = out * i;
	return out % MOD;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long h,m,out;

    while (cin >> h >> m)
    {    	
    	long long f1 = factorial(h);
    	long long f2 = factorial(h+1);
    	long long f3 = factorial((h+1) -m);
   
    	long long n1 = f1;
    	long long n2 = f2 / f3;
	out = (n1*n2) %MOD;
	cout<<out<<'\n';    	
    }    
    return 0; 
}
