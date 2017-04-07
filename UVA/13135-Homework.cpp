/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/131/13135.pdf
   Topic: Data structures and basic maths */
#include <iostream>
#include <map>

using namespace std;

map<int, int>m;

void init()
{
  int n = 1, sum;
  do{
    sum = (n+1) * (n+2) / 2;
    m[sum] = n++;
  }while(sum < 50000000);
}

int main()
{
  int t, p;

  init();

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&p);
    if(m.find(p) != m.end())
      printf("%d\n",m[p]);
    else
      printf("No solution\n");
  }

  return 0;
}
