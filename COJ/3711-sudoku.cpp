#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
	int t, n, box_size;
	bool ans;
	scanf("%d",&t);

	while(t--)
	{
		ans = true;
		scanf("%d",&n);
		box_size = sqrt(n);
		int sudoku[n][n];	

		for(int i = 0; i < n; i++)
			for(int j = 0; j< n; j++)
				scanf("%d",&sudoku[i][j]);

		//review lines

		bool m[(box_size * box_size) + 1];
		for(int i = 0; i < n; i++)
		{
			memset(m, false, sizeof(m));
			for(int j = 0; j < n; j++)
			{
				if(!m[sudoku[i][j]]) m[sudoku[i][j]] = true;
				else{ ans = false; break;}
			}
		}

		if(ans)
		{
			//review columns
			for(int i = 0; i < n; i++)
			{
				memset(m, false, sizeof(m));
				for(int j = 0; j < n; j++)
				{
					if(!m[sudoku[j][i]]) m[sudoku[j][i]] = true;
					else{ ans = false; break;}
				}
			}
		}

		if(ans)
		{
			//review boxes
			for(int horizontal = 0; horizontal < n; horizontal += box_size)
			{
				for(int vertical = 0; vertical < n; vertical += box_size)
				{
					memset(m, false, sizeof(m));
					for(int i = vertical; i < box_size; i++)
					{
						for(int j = horizontal; j < box_size; j++)
						{
							if(!m[sudoku[j][i]]) m[sudoku[j][i]] = true;
							else{ ans = false; break; }
						}
					}
				}
			}
		}

		if(ans)
			printf("yes\n");
		else
			printf("no\n");


	}
	return 0;
}