/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/129/12908.pdf
   Topic: Binary search (bits implementation) */
#include <iostream>

using namespace std;

long long sum;

long long calculateSum(long long n)
{
  return n * (n+1) / 2;
}

long long f(long long minPage)
{
  return calculateSum(minPage) > sum;
}

long long solve()
{
  long long minPage = (1LL << 32) - 1LL;

  for(int i = 31; i >= 0; i--)
    minPage ^= f(minPage ^ (1LL << i)) << i;

  return minPage;
}

int main()
{
  long long minPage, forgotten, totalPages;

  while(scanf("%lld",&sum) && sum)
  {
    minPage    = solve();
    forgotten  = calculateSum(minPage) == sum ? minPage + 1 : calculateSum(minPage) - sum;
    totalPages = calculateSum(minPage) == sum ? minPage + 1 : minPage;
    printf("%lld %lld\n", forgotten, totalPages);
  }

  return 0;
}