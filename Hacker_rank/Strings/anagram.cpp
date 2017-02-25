#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int t, hash[26], ans;
  string str;

  scanf("%d",&t);
  
  while(t--)
  {
    cin >> str;
    memset(hash, 0, sizeof(hash));
    ans = 0;
    
    if(str.length() % 2 != 0)
      printf("-1\n");
    else
    {
      for(int i = str.length() / 2; i < str.length(); i++)
        hash[str[i] - 'a']++;
        
      for(int i = 0; i < str.length() / 2; i++)
      {
        if(hash[str[i] - 'a'] == 0) ans++;
        else hash[str[i] - 'a']--; 
      }

      printf("%d\n",ans);
    } 
  }
  return 0;
}
