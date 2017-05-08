/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: http://codeforces.com/problemset/problem/471/D
   Topic: Z-algorithm   */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> zAlgorithm(vector<int> &v){
  vector<int> z(v.size());

  int l = 0, r = 0, n = v.size(), k;
  for(int i = 1; i < n; i++){
    if(i > r){
      l = r = i;
      while(r < n && v[r-l] == v[r]) r++;
      z[i] = r-l; r--;
    }
    else{
      k = i - l;
      if(z[k] < r-i+1) z[i] = z[k];
      else{
        l = i;
        while(r < n && v[r-l] == v[r]) r++;
      }
      z[i] = r-l; r--;
    }
  }

  return z;
}

int main()
{
  int n, w, ant, curr, subset;
  vector<int> bears, elephant;
  while(scanf("%d %d",&n, &w) != EOF){
    scanf("%d",&ant);
    for(int i = 1; i < n; i++){
      scanf("%d",&curr);
      bears.push_back(curr - ant);
      ant = curr;
    }
    scanf("%d",&ant);
    for(int i = 1; i < w; i++){
      scanf("%d",&curr);
      elephant.push_back(curr - ant);
      ant = curr;
    }

    vector<int> concat;
    if(n < w){
      subset = n-1;
      for(auto b : bears)
        concat.push_back(b);
      concat.push_back(INT_MIN);
      for(auto e : elephant)
        concat.push_back(e);
    }else{
      subset = w-1;
      for(auto e : elephant)
        concat.push_back(e);
      concat.push_back(INT_MIN);
      for(auto b : bears)
        concat.push_back(b);
    }

    int ans = 0;
    for(auto z : zAlgorithm(concat))
      if(z == subset) ans++;

     cout << ans << endl;
  }
  return 0;
}