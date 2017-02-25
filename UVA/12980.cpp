#include <iostream>
using namespace std;

long long formula(long long n)// formula para obetener 1+2+3+4+...n
{
	return (n*(n+1))/2;
}
int main()
{
	long long n, out;
	while(cin>>n && n)
	{
		long long inf = 1, sup = 100000000, med;
		while(inf <= sup)//Haciendo busqueda binaria
		{
			med = (inf + sup) / 2;
			if(formula(med) == n)
			{
				cout<<med+1<<" "<<med+1<<endl;
				break;
			}
			else if(formula(med) > n && formula(med-1) < n)
			{
				cout<<formula(med)-n<<" "<<med<<endl;
				break;
			}
			else if(formula(med) < n && formula(med+1) > n)
			{
				cout<<formula(med+1)-n<<" "<<med+1<<endl;
				break;
			}
			else if(formula(med) > n)
				sup = med - 1; 
			else
				inf = med + 1; 
		}

	}
	return 0;
}