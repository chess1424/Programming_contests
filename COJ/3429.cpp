//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3429&cid=1479

#include <iostream>
#include <stdio.h>
#include <map>
#define MOD 1000000007;

using namespace std;

map<long long, long long> m;

long long compute(long long n)
{
	if(m[n]) return m[n];
	
	if(n % 2 == 0)
		compute(n-1);
		
	else
	{
		m[n] = (n*n + compute(n-2)) % MOD;
		return m[n];
	}
}

int main(int argc, char const *argv[])
{
	long long n;
	m[1] = 1;
	
	while(scanf("%lld",&n) != EOF)
		printf("%lld\n",compute(n));
	
	return 0;
}