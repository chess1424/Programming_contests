//Carlos Roberto Martinez Ojeda 
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3426&cid=1479

#include <stdio.h>
#include <cmath>
int main(int argc, char const *argv[])
{
	long long a,b,n,end,begin,f;
	while(scanf("%lld %lld",&a,&b) != EOF)
	{
		end = a+b-1;
		begin = std::abs(a-b) + 1; 
		n = end;
		f = (n * (n+1)) / 2;
		n = begin - 1;
		f -= (n * (n+1)) /2; 
		printf("%lld\n",f);
	}
	return 0;
}
