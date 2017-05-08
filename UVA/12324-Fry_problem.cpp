/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/123/12324.pdf
   Topic: DP   */

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>

#define maxSize 110

using namespace std;

int trips[maxSize], spheres[maxSize], dp[maxSize][1200];

int f(int i, int totalSpheres, const int &n)
{
  if (i == n) return 0;

  if(dp[i][totalSpheres] != -1) return dp[i][totalSpheres];

  if(totalSpheres)
    return dp[i][totalSpheres] =
               min(trips[i]/2 + f(i+1, totalSpheres-1+spheres[i], n),
                   trips[i] + f(i+1, totalSpheres+spheres[i], n));
  else
    return dp[i][totalSpheres] =
               trips[i] + f(i+1, totalSpheres+spheres[i], n);
}

int main()
{
  int n;
  while(scanf("%d",&n) != EOF && n){
    fill(&dp[0][0], &dp[maxSize][0], -1);

    for(int i = 0; i < n; i++)
      scanf("%d %d", &trips[i], &spheres[i]);

    printf("%d\n",f(0,0,n));
  }

  return 0;
}