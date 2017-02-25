#include <iostream>
#include <vector>

using namespace std;

typedef struct numbers
{
	int digits[10] = {0};
}numbers;

int main()
{
	int n, num, queryes, l, r, many, ans;
	while(scanf("%d",&n) != EOF)
	{
	  vector<numbers>arr(n+1);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < 10; j++)
				arr[i].digits[j] = arr[i-1].digits[j];

			scanf("%d",&num);
			arr[i].digits[num] += 1;
		} 

		scanf("%d",&queryes);
		for(int i = 0; i < queryes; i++)
		{
			many = ans = 0;
			scanf("%d %d",&l,&r);

			for(int i = 0; i < 10; i++)
			{
				many = arr[r].digits[i] - arr[l-1].digits[i];
				if(many > 0) ans++;
			}
			
			printf("%d\n",ans);
		}

	}
	return 0;
}