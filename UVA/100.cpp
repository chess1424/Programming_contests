#include <iostream>

using namespace std;

int main()
{
	int a, b, c, n, out;
	while(cin>>a>>b)
	{
		out = 0; 
		for(int i = min(a,b); i <= max(a,b); i++)
		{
			c = 1; n = i;
			while(n != 1)
			{
				n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
				c++;
			}
			out = max(out, c);
		}
		cout<<a<<" "<<b<<" "<<out<<'\n';
	}
	return 0;
}