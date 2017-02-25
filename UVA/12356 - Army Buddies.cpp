// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/external/123/12356.pdf

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int s, b, l, r, left[100001], right[100001];
	while(scanf("%d %d",&s,&b) && s && b)
	{
		for(int i = 1; i <= s; i++)
		{
			left[i] = i - 1;
			right[i] = i + 1; 
		}

		left[1] = -1;
		right[s] = -1;

		for(int i = 0; i < b; i++)
		{
			scanf("%d %d",&l,&r);
			if(left[l] != -1)
				right[left[l]] = right[r];
			if(right[r] != -1)
				left[right[r]] = left[l];

			if(left[l] != -1)
				printf("%d ",left[l]);
			else
				printf("* ");
			if(right[r] != -1)
				printf("%d\n",right[r]);
			else
				printf("*\n");
			
		}
		printf("-\n");
	}

}
