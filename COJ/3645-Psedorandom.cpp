#include <iostream>
#include <map>

using namespace std;

int main()
{
	int a, c, m, seed, counter;
	while(scanf("%d %d %d %d",&a, &c, &m, &seed) != EOF)
	{
		map<int, int> numbers;
		counter = 1;
		while(numbers[seed] == 0)
		{
			numbers[seed] = counter++;
			seed = (seed * a + c) % m;
		}
		printf((counter - numbers[seed] == m) ? "YES " : "NO ");
		printf("%d %d %d\n",counter-1, numbers[seed]-1, counter-numbers[seed]);
	}
	return 0;
}