#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n, m, s, t, x, y;
	long long ans;
	while(scanf("%d %d %d %d",&n, &m, &s, &t) != EOF)
	{
		ans = 0;
		vector< vector<int> >adj_list(n);

		for(int i = 0; i < m; i++)
		{
			scanf("%d %d",&x, &y);
			adj_list[x].push_back(y);
			adj_list[y].push_back(x);
		}

		long long times[t+1][n];
		for(int i = 0; i < t+1; i++)
			fill(times[i], times[i]+n, 0);

		times[0][s] = 1;

		for(int minute = 1; minute <= t; minute++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < adj_list[i].size(); j++)
					if(times[minute - 1][adj_list[i][j]])
						times[minute][i] += times[minute-1][adj_list[i][j]];
		
		for(int i = 0; i < n; i++)
			ans += times[t][i];

		printf("%lld\n",ans);		
	} 
	return 0;
}