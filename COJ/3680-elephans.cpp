#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	long long m, w, weight, sum, ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&m,&w);
		vector<long long> v; 
		sum = ans = 0;
		for(long long i = 0; i < m; i++)
		{
			scanf("%lld",&weight);
			v.push_back(weight);
		}
		sort(v.begin(), v.end());

		for(long long i = 0; i < m; i++)
		{
			sum += v[i];
			if(sum > w) break;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}