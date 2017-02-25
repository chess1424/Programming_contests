#include <iostream>
#include <string>

using namespace std;

int main()
{
  int t, ans;
  string str;
  char c;
  scanf("%d",&t);

  while(t--)
  {
    ans = 0; 
    cin >> str;
    c = str[0];
    for(int i = 1; i < str.length(); i++)
    {
      if(str[i] == c)
        ans++;
      else
        c = str[i];
    }

    printf("%d\n",ans);
  }
  return 0;
}
