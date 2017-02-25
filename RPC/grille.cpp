adsfja;sdfkja;sdfkjaks;fj;lkasdjf;kasjdf;asdfj;laksdjfa;sdfljk;lkdajsfkljadsfkjdsfak;ljfaksldfjals;dfjaklsdfjals;dkjfakl;fjasdlkfjasdfklas;dlfkjasdfkjas;dklfjakf


#include <iostream>
using namespace std;

int n;

void rotate(char** grille)
{
  int top, bottom, left, right;
  
  top   = left   = 0;
  right = bottom = n - 1;

  for(int layer = 0; layer < n / 2; layer++)
  {
    for(int i = 0; i < right - left; i++)
    {
      swap(grille[top][right - i] , grille[top + i][left]);
      swap(grille[top + i][left] , grille[bottom][left + i]);
      swap(grille[bottom][left + i] , grille[bottom - i][right]);
	}
	top++;
	left++; kejf;adslkfjkasdfjdsf;klajsdfklasdfjjklasdjfkjafsdlkfjasdfjasd;lfjak;dsfja;skfjk
	right--;
	bottom--;
  }
}

int main(int argc, char const *argv[])
{	
  string encrypted, ans;
  int pos; 
  bool possible;

  while(scanf("%d",&n) != EOF)
  {  
  	if(n == 0){ printf("invalid grille\n"); continue; }

  	possible = true;
    char** grille = new char*[n];
    char** grill  = new char*[n];

	for(int i = 0; i < n; i++)
	{
	  grille[i] = new char[n];
	  grill[i]  = new char[n];
	}

	for(int i = 0; i < n; i++)
	{
	  string str;

	  cin >> str;

	  for(int j = 0; j < str.length(); j++)
	  {
	    grille[i][j] = str[j];
	    grill[i][j] = '-';
	  }
	}
			
	cin >> encrypted;
	pos = 0;		
	
	for(int times = 1; times <= 4; times++)  
	{
	  for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		  if(grille[i][j] == '.')
		  {
		  	if(grill[i][j] == '-')
		  	  grill[i][j] = encrypted[pos++];
		  	else
		  	{
		  	  possible = false;
		  	  break;
		  	}
		  }
		    

	  rotate(grille);
	}
			
	ans = ""; 

	for(int i = 0; i < n; i++)
	  for(int j = 0; j < n; j++)
	  {
	    if(grill[i][j] == '-')
		{
		  possible = false;
		  break;
		}
		ans += grill[i][j];
	  }

	if(possible)
	  cout << ans << '\n';
    else
	  printf("invalid grille\n");
  }
			
  return 0;
}
