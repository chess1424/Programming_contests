//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3333&cid=1479

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,suma,num,a,b;
	while(scanf("%d",&n) != EOF)
	{
		vector<int> v(n+1);
		suma = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&num);
			suma += num;
			v[i] = suma;  
		}

		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",v[b] - v[a-1]);
		}
	}
	return 0;
}