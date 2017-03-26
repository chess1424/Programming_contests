/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@@live.com.mx>
   Problem_statement: https://uva.onlinejudge.org/external/7/719.pdf
   Topic: Suffix Array */

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct suffix{
  int index;
  int rank[2];
}suffix;

bool mySort(suffix a, suffix b)
{
  if(a.rank[0] != b.rank[0]) return a.rank[0] < b.rank[0];
  else return a.rank[1] < b.rank[1];
}

int *constructSA(string &str)
{
  int n   = str.length(), nextIndex;
  int *SA = new int[n];
  suffix suffixes[n];

  //fill initial suffix
  for(int i = 0; i < n; i++)
  {
    suffixes[i].index   = i;
    suffixes[i].rank[0] = str[i] - 'a';
    suffixes[i].rank[1] = (i + 1 < n) ? str[i + 1] - 'a' : -1;
  }

  sort(suffixes, suffixes + n, mySort);

  //compute states for 4, 8, 2^n
  int indexes[n];

  for(int k = 2; k < n; k <<= 1)
  {
    //assing first rank
    suffix prevSuffix          = suffixes[0];
    suffixes[0].rank[0]        = 0;
    indexes[suffixes[0].index] = 0;

    for(int i = 1; i < n; i++)
    {
      if(prevSuffix.rank[0] == suffixes[i].rank[0] &&
         prevSuffix.rank[1] == suffixes[i].rank[1])
        suffixes[i].rank[0] = suffixes[i-1].rank[0];
      else
      {
        prevSuffix = suffixes[i];
        suffixes[i].rank[0] = suffixes[i-1].rank[0] + 1;
      }
      indexes[suffixes[i].index] = i;
    }

    //assign second rank
    for(int i = 0; i < n; i++)
    {
      nextIndex = suffixes[i].index + k;
      suffixes[i].rank[1] = (nextIndex < n) ? suffixes[indexes[nextIndex]].rank[0] : -1;
    }

    sort(suffixes, suffixes + n, mySort);
  }

  //Extract the output
  for(int i = 0; i < n; i++)
    SA[i] = suffixes[i].index;

  return SA;
}


int main()
{
  int T;
  string str, prevStr;

  cin >> T;
  while(T--)
  {
    cin >> str;
    str += str;

    int *SA = constructSA(str), output = INT_MAX, n = str.length();
    prevStr = "";

    for(int i = 0; i < n; i++)
    {
      if(SA[i] < n/2)
      {
        if(!prevStr.length())
          prevStr = str.substr(SA[i], n/2);

        if(str.substr(SA[i] , n/2) == prevStr)
          output = min(SA[i], output);
        else
        {
          cout << output + 1 << endl;
          break;
        }

        if(i == n-1) cout << output + 1 << endl;

        prevStr = str.substr(SA[i], n/2);
      }
    }
  }
  return 0;
}
