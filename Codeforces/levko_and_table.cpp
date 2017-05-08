/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: http://codeforces.com/problemset/problem/361/A
   Topic: ad-hoc */

#include <iostream>

using namespace std;

int main()
{
  int n, k;
  while(scanf("%d %d",&n, &k) != EOF){
    int aux = n-1;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(j == aux){
          aux--;
          cout << k << " ";
        }
        else
          cout << 0 << " ";
      }cout << '\n';
    }

  }
  return 0;
}