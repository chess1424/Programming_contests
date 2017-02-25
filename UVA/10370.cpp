#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t,n; 
	float promedio, suma, calif, contador;
	cin>>t;
	while(t--)
	{
		cin>>n;
		suma = 0;
		float estudiantes[n];
		
		for(int i = 0; i < n; i++)
		{
			cin>>estudiantes[i];
			suma += estudiantes[i];
		}
		promedio = suma / n;
		contador = 0;

		for(int i = 0; i < n; i++)
			if(estudiantes[i] > promedio) contador++;

		cout<<fixed<< std::setprecision(3)<<(contador*100)/n<<"%"<<endl;
	}
	return 0;
}