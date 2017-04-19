/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://www.codechef.com/APRIL17/problems/ROWSOLD */
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

long long solve(const string& cells)
{
  long long ans = 0, spaces = 0, soldiers = 0;

  for(auto cell : cells){
    if(cell == '1'){
      if(spaces)
        ans += spaces * soldiers + soldiers;

      spaces = 0;
      soldiers++;
    }
    else{
      if(soldiers)
        spaces++;
    }
  }
  if(spaces)
    ans += spaces * soldiers + soldiers;

  return ans;
}

int main()
{
  int t; scanf("%d",&t);
  string cells;
  while(t--){
    cin >> cells;
    cout << solve(cells) << '\n';
  }
  return 0;
}