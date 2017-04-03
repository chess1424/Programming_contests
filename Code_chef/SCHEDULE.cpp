/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/7/719.pdf
   Topic: Binary search */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <climits>

using namespace std;

bool canAlternate(string &bits, int k)
{
  int size = bits.length(), flips, minFlips = INT_MAX;

  for(int i = 0; i <= 1; i++){
    bool bit = i; flips = 0;
    for(int j = 0; j < size; j++){
      if(bits[j] - '0' != bit) flips++;
      bit = !bit;
    }
    minFlips = min(minFlips, flips);
  }
  if(minFlips <= k)
    return true;
  else
    return false;
}

bool isPossible(vector<int> &segments, int k, int m)
{
  int size = segments.size();
  for(int i = 0; i < size; i++){
    if(segments[i] <= m) continue;

    k -= segments[i] / (m+1);

    if(k < 0) return false;
  }

  return true;
}

int solve(string &bits, vector<int> &segments, int n, int k)
{
  if(k >= n || canAlternate(bits, k)) return 1;

  int l = 2, r = n, m;

  while(l <= r)
  {
    m = (l + r) / 2;

    if(isPossible(segments, k, m))
      r = m - 1;
    else
      l = m + 1;
  }

  return l;
}

int main()
{
  int t,n,k,segmentLength;
  string bits;

  scanf("%d",&t);
  while(t--)
  {
    vector<int> segments;

    scanf("%d %d",&n,&k); cin >> bits;
    segmentLength = 1;

    for(int i = 1; i < n; i++)
    {
      if(bits[i] == bits[i-1])
        segmentLength++;
      else{
        segments.push_back(segmentLength);
        segmentLength = 1;
      }
    }segments.push_back(segmentLength);

    printf("%d\n",solve(bits, segments, n, k));
  }
  return 0;
}