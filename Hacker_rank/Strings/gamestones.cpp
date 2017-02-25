#include <iostream>
#include <string.h> 

using namespace std;

int main()
{
  int n, arr[26], ans = 0;
  string str;

  memset(arr, 0 , sizeof(arr));

  scanf("%d",&n);
  
  for(int i = 1; i <= n; i++)
  {
    cin >> str;
   
    for(int j = 0; j < str.length(); j++)
      if(arr[str[j] - 'a'] == i-1)
        arr[str[j] - 'a']++;
  }

  for(int i = 0; i < 26; i++)
    if(arr[i] == n) ans++;

  printf("%d\n", ans);
  
  return 0;
}
