#include <iostream>

using namespace std;

int main()
{
  int t, r;
  string str;
  bool funny;
  
  scanf("%d",&t);
  
  while(t--)
  {
    cin >> str;
    
    r = str.length() - 2;
    funny = true;
    for(int i = 1; i < str.length(); i++)
    {
      if( abs( str[i]-str[i-1] ) != abs( str[r] - str[r+1] ) )
      {
        funny = false;
        break;
      }
      r--;
    }

    if(funny)
      printf("Funny\n");
    else
      printf("Not Funny\n");
      
  }
  return 0;
}
