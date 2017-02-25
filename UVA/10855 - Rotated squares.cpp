// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1796

#include <bits/stdc++.h>
using namespace std;

int N,n;

void rotate(char** arr)
{
	int top, bottom, left, right;
	top = left = 0;
	right = bottom = n - 1;
	for(int layer = 0; layer < n / 2; layer++)
	{
		for(int i = 0; i < right - left; i++)
		{
			swap(arr[top][right - i] , arr[top + i][left]);
			swap(arr[top + i][left] , arr[bottom][left + i]);
			swap(arr[bottom][left + i] , arr[bottom - i][right]);
		}
		top++;
		left++;
		right--;
		bottom--;
	}
}

int check(char** sN, char** sn)
{
	
	int out, r, c, si, sj;
	r = c = out = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(sN[i][j] == sn[0][0])
			{
				r = i; c = j;
				for(si = 0; si < n; si++)
				{
					for(sj = 0; sj < n; sj++)
					{
						if(r == N || c== N || sn[si][sj] != sN[r][c])
						{
							si = n + 1;
							break;
						}
						c++;
					}
					c = j;
					r++;
				}
				if(si != n + 2) 
					out += 1;
			}
		}
	}
	return out;
}

int main(int argc, char const *argv[])
{	
	while(scanf("%d %d",&N,&n) && N && n)
	{
		char** sN = new char*[N];
		char** sn = new char*[n];

		for(int i = 0; i < n; i++)
			sn[i] = new char[n];
		for(int i = 0; i < N; i++)
			sN[i] = new char[N];

		for(int i = 0; i < N; i++)	
			for(int j = 0; j < N; j++)
				scanf(" %c",&sN[i][j]);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf(" %c",&sn[i][j]);

		printf("%d ",check(sN,sn));
		rotate(sn);
		printf("%d ",check(sN,sn));
		rotate(sn);
		printf("%d ",check(sN,sn));
		rotate(sn);
		printf("%d\n",check(sN,sn));
	}
			
	return 0;
}
