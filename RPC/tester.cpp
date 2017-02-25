#include <iostream>
#include <ctime>
using namespace std;

int main()
{

	int desde = 0, hasta = 1, raiz, num , n;
	int times = 20000;
	while(times--)
	{
		desde = 0; hasta = 1;
		int n = rand()%(hasta-desde+1)+desde;

		cout << n << " "; 

		desde = 0; hasta = 100000;

		for(int i = 0; i < n; i++)
		{
			num = rand()%(hasta-desde+1)+desde;
			cout << num << " ";
		}

		num = rand()%(hasta-desde+1)+desde;
		
		cout << num << endl;
	}
}