//Carlos Roberto Martinez Ojeda
//http://coj.uci.cu/contest/cproblem.xhtml?pid=3441&cid=1479


#include <stdio.h>

int main(int argc, char const *argv[])
{
	int t,out,m;
	scanf("%d",&t);
	
	for(int i = 1; i <= t; i++)
	{
		
		scanf("%d",&m);
		if(m == 1)
			out = 0;
		else if(m >= 2 && m <= 3)
			out = 1;
		else if(m >= 4 && m <= 7)
			out = 2;
		else if(m >= 8 && m <= 15)
			out = 3;
		else if(m >= 16 && m <= 31)
			out = 4;
		else if(m >= 32 && m <= 63)
			out = 5;
		else if(m >= 64 && m <= 127)
			out = 6;
		else if(m >= 128 && m <= 255)
			out = 7;
		else if(m >= 256 && m <= 511)
			out = 8;
		else 
			out = 9;

		printf("Case #%d: %d\n",i,out);
	}
	return 0;
}