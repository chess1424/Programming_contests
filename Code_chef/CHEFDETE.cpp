#include <bits/stdc++.h>
#define MAXSIZE 100001
using namespace std;

int main()
{
  int n,num;
  bool arr[MAXSIZE];

  while(scanf("%d",&n) != EOF)
  {
    memset(arr,false,sizeof(arr));
    for(int i = 1; i <= n; i++)
    {
      scanf("%d",&num);
      arr[num] = true;
    }
    bool first = true;
    for(int i = 1; i <= n; i++)
    {
      if(!arr[i])
      {
        if(!first)
          printf(" %d",i);
        else
        {
          printf("%d",i);
          first = false;
        }
      }
    }
    printf("\n");
  }

  return 0;
}