// Carlos Roberto Martinez Ojeda
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1861

#include <bits/stdc++.h>
using namespace std;	
int main(int argc, char const *argv[])
{
	long sz, p;
	long flayer, llayer, med, fnum, lnum, sobra, left, bottom, right, top, size, num, i ,j, ant;
	while(scanf("%ld %ld",&sz,&p) && sz && p)
	{
		flayer = 1;
		llayer = sz / 2 + 1;

		if(p == 1)
		{
			printf("Line = %ld, column = %ld.\n",sz / 2 + 1, sz / 2 + 1);
			continue;
		}
		
		while(flayer <= llayer)//Binary search
		{
			med = (flayer + llayer) / 2;
			fnum = ((med - 1) * 2 - 1) * ((med - 1) * 2 - 1) + 1;
			lnum = (med * 2 - 1) * (med * 2 - 1);

			if(p < fnum)
				llayer = med - 1;
			else if(p > lnum)
				flayer = med + 1;
			else
			{
				size = med * 2 - 1;
				sobra = (sz - size) / 2;
				left = bottom = 1 + sobra;
				right = top = sz - sobra;
				
				num = fnum + size - 2;
				if(p <= num)
				{
					i = top;
					j = right - 1 - (p - fnum);
					printf("Line = %ld, column = %ld.\n",i,j);
					break;
				}
				ant = num;
				num += size - 1;
				if(p <= num)
				{
					i = top - (p - ant);
					j = left;
					printf("Line = %ld, column = %ld.\n",i,j);
					break;
				}
				ant = num;
				num += size - 1;
				if(p <= num)
				{
					i = left;
					j = left + (p - ant);
					printf("Line = %ld, column = %ld.\n",i,j);
					break;
				}
				ant = num;
				num += size - 1;

				i = bottom + (p - ant);
				j = right;
				printf("Line = %ld, column = %ld.\n",i,j);
				break;
			}
		}
	}
	return 0;
}