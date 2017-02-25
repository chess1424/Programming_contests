#include <iostream>
#include <vector>
#include <string.h>
#define SIZE 100001

using namespace std;

int main()
{
	bool triangular[SIZE + 1];
	memset(triangular, false, sizeof(triangular));
	for(long long i = 0, j = 0; (j+=i) < SIZE; i++)
		triangular[j] = true;

	long long n, i , j;
	while(scanf("%lld",&n) != EOF)
	{
		if(triangular[n])
		{
			printf("1\n");
		}
		else
		{	
			for(i = 0, j =0; (j += i) <= n; i++)
				if(triangular[n-j]) break;

			if(n-j >= 0)
				printf("2\n");
			else
				printf("3\n");
		}
	}
	return 0;
}