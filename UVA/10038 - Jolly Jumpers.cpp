// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=979

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,num,tam;
	bool jolly;
	map<int,bool> m;
	while(scanf("%d",&n) != EOF)
	{	
		jolly = true;
		vector<bool> v(n+1,false);
		vector<int> v2(n);
		for(int  i = 0; i < n; i++)
			scanf("%d",&v2[i]);

		tam = v2.size() - 1;
		if(tam == 0)
			printf("Jolly\n");
		else
		{
			for(int i = 0; i < tam; i++)
			{
				num = abs(v2[i] - v2[i+1]);
				if(num < 1 || num > n - 1)
				{
					jolly = false;
					break;
				}
				else
				{
					v[num] = true;
				}
			}

			if(!jolly)
				printf("Not jolly\n");
			else
			{
				for(int i = 1; i <= n-1; i++)
				{
					if(v[i] == false)
					{
						jolly = false;
						break;
					}
				}
				if(jolly)
					printf("Jolly\n");
				else
					printf("Not jolly\n");
			}
			
		}
		
		
	}

	
	return 0;
}
