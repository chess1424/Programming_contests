#include <iostream>

using namespace std;

int main()
{
	int n,m,c = 1,suma;
	
	while(cin>>n>>m && n && m)
	{
		char arr[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin>>arr[i][j];
		if(c != 1)cout<<endl;
		cout<<"Field #"<<c++<<":"<<'\n';
	
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				suma = 0;
				if(arr[i][j] != '*')
				{

					if(i > 0)
					{
						if(j > 0)
							if(arr[i-1][j-1] == '*') suma++;
						if(j < m-1)
							if(arr[i-1][j+1] == '*') suma++;
						if(arr[i-1][j] == '*') suma++;
					}
					if(i < n-1)
					{
						if(j > 0)
							if(arr[i+1][j-1] == '*') suma++;
						if(j < m-1)
							if(arr[i+1][j+1] == '*') suma++;
						if(arr[i+1][j] == '*') suma++;
					}
					if(j > 0)
						if(arr[i][j-1] == '*') suma++;
					if(j < m-1)
						if(arr[i][j+1] == '*') suma++;
					
					cout<<suma;
				}
				else
					cout<<'*';
			}
			cout<<endl;
		}
		
	}
	return 0;
}