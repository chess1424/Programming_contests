#include <iostream>
#include <string.h>

using namespace std;


long long v[1000][1000];
long long c(long long i, long long j)
{
	if(j == 1 || i == j) return 1;
	if(v[i][j] != -1) return v[i][j];
	return v[i][j] = c(i-1, j-1) + c(i-1, j);
}

int main()
{
	memset(v, -1, sizeof(v));
	int t;
	long long n, ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n == 1) ans = 1;
		else if(n == 2) ans = 2;
		else if(n == 3) ans = 4;
		else ans = c(n+1,5) + c(n+1,3) + 1;
		printf("%lld\n",ans);
	}
	return 0;
}