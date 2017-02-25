//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3433&cid=1479

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int x,y,n,arr[101],s,w,u;
	bool pX[101], pY[101];
	while(scanf("%d %d",&x,&y) != EOF)
	{
		memset(arr,0,sizeof(arr));
		memset(pX,false,sizeof(pX));
		memset(pY,false,sizeof(pY));
		s = w = u = 0;
		for(int i = 0; i < x; i++)
		{
			scanf("%d",&n);
			if(!pX[n]) arr[n]++;
			pX[n] = true;
		}
		for(int i = 0; i < y; i++)
		{
			scanf("%d",&n);
			if(!pY[n]) arr[n]++;
			pY[n] = true;
		}

		for(int i = 1; i <= 100; i++)
		{
			if(arr[i] == 1) w++;
			else if(arr[i] == 2 ) s++;
			else u++;
		}

		printf("Unsolvable: %d\n",u);
		printf("Weakly solvable: %d\n",w);
		printf("Strongly solvable: %d\n",s);
	}
	return 0;
}