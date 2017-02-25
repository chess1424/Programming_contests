#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num, n;
	double div, ans;
	while(scanf("%d",&num) && num)
	{
		n = (num>>1); div = num-1;
		if(num % 2 != 0)//is odd
		{
			//Apply even sum
			ans = 2.0*2.0*n*(n+1.0)*(2.0*n+1.0);
		}
		else
		{
			//Apply odd sum
			ans = 2.0*n*(2.0*n-1.0)*(2.0*n+1.0);
		}
		ans /= 3.0;
		ans /= div;
		printf("%lf\n",sqrt(ans));
	}
	return 0;
}