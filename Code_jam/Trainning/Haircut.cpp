/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://code.google.com/codejam/contest/4224486/dashboard#s=p1&a=1
   Topic: Binary search */

#include <iostream>

using namespace std;

long long barbers[1000];

long long calculateCustomers(const long long &minute, const int &B)
{
  long long customers = 0;

  for(int i = 0; i < B; i++)
    customers += minute / barbers[i];
  customers += B;

  return customers;
}

long long f(long long minute, const int &B, const long long &N)
{
  return calculateCustomers(minute, B) >= N;
}

int solve(const int &B, const long long &N)
{
  for(int i = 0; i < B; i++)
    scanf("%lld",&barbers[i]);

  long long minute = (1LL << 42LL) - 1LL;

  for(long long i = 41; i >= 0; i--)
    minute ^= f(minute ^ (1LL << i), B, N) << i;

  if(minute == 0)
    return N;

  long long customers = calculateCustomers(minute, B);

  for(int i = 0; i < B; i++)
    if(minute % barbers[i] == 0) customers--;

  for(int i = 0; i < B; i++)
    if(minute % barbers[i] == 0 && ++customers == N)
      return i+1;

  return B;
}

int main()
{
  int T,B; scanf("%d",&T);
  long long N;

  for(int test = 1; test <= T; test++){
    scanf("%d %lld",&B,&N);
    printf("Case #%d: %d\n",test, solve(B, N));
  }

  return 0;
}
