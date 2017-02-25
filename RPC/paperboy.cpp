#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int left_houses, right_houses;
vector<int> v;

long long compute_left(int origin, bool first)
{
	int sobran = left_houses % 5, viajes = left_houses / 5, aux;
	long long ans = 0;

	if(sobran > 0)
	{
		if(viajes > 0 || (first && right_houses > 0))
			ans += abs(v[origin] - v[origin - sobran]) * 2;
		else
			ans += abs(v[origin] - v[origin - sobran]);
	}

	aux = origin - sobran - 5;

	for(int i = 0; i < viajes; i++)
	{
		if(i < viajes - 1)
		{
			ans += abs(v[origin] - v[aux]) * 2;
		}
		else
		{
			if(first && right_houses > 0)
				ans += abs(v[origin] - v[aux]) * 2;
			else
				ans += abs(v[origin] - v[aux]);
		}
		aux -= 5;
	}

	return ans;
}

long long compute_right(int origin, bool first)
{
	int sobran = right_houses % 5, viajes = right_houses / 5, aux;
	long long ans = 0;

	if(sobran > 0)
	{
		if(viajes > 0 || (first && left_houses > 0))
			ans += abs(v[origin] - v[origin + sobran]) * 2;
		else
			ans += abs(v[origin]  - v[origin + sobran]);
	}

	aux = origin + sobran + 5;

	for(int i = 0; i < viajes; i++)
	{
		if(i < viajes - 1)
		{
			ans += abs(v[origin] - v[aux]) * 2;
		}
		else
		{
			if(first && left_houses > 0)
				ans += abs(v[origin] - v[aux]) * 2;
			else
				ans += abs(v[origin] - v[aux]);
		}
		aux += 5;
	}
	return ans;
}

int main()
{
	int n, num, x, origin;
	bool is_origin;

	while(scanf("%d", &n) != EOF)
	{
		is_origin = false;

		for(int i = 0; i < n; i++)
		{
			scanf("%d",&num);
			v.push_back(num);
		}

		scanf("%d",&x);
		for(int i = 0; i < n; i++)
			if(v[i] == x){ is_origin = true; break; }

		if(!is_origin) v.push_back(x);

		sort(v.begin(), v.end());

		for(int i = 0; i < v.size(); i++)
			if(v[i] == x){ origin = i; break; }

		left_houses = origin;
		right_houses = (v.size() - 1) - origin;

		long long dist_left, dist_right;
		dist_left = abs(v[origin] - v[0]);
		dist_right = abs(v[origin] - v[v.size()-1]);

		if(dist_left < dist_right)
			printf("%lld\n",compute_left(origin, true) + compute_right(origin, false) + n);
		else
			printf("%lld\n",compute_right(origin, true) + compute_left(origin, false) + n);

		v.clear();

	}
	return 0;
}
