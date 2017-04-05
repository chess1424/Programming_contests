/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://code.google.com/codejam/contest/4224486/dashboard#s=p0&a=1
   Topic: Binary search */

#include <iostream>
#include <climits>
#define maxSize 1000

using namespace std;

int intervals[maxSize], N;

int computeFirst()
{
  int ans = 0;
  for(int i = 1; i < N; i++)
    if(intervals[i-1] - intervals[i] > 0)
      ans += intervals[i-1] - intervals[i];

  return ans;
}

int computeSecond()
{
  int ans = 0, rate = 0;
  for(int i = 1; i < N; i++)
    if(intervals[i-1] - intervals[i] > 0)
      rate = max(rate, intervals[i-1] - intervals[i]);

  for(int i = 0; i < N-1; i++)
    ans += min(rate, intervals[i]);

  return ans;
}

int main()
{
  int T;
  scanf("%d",&T);
  for(int test = 1; test <= T; test++)
  {
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
      scanf("%d",&intervals[i]);

    printf("Case #%d: %d %d\n",test, computeFirst(), computeSecond());
  }
  return 0;
}
