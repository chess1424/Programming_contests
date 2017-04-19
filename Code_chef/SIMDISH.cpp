/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://www.codechef.com/problems/SIMDISH */
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
  int t, ingredients = 4;
  string ingredient;
  scanf("%d",&t);

  while(t--)
  {
    map<string, int> m;
    int frecuency = 0;

    for(int i = 0; i < ingredients; i++){
      cin >> ingredient;
      m[ingredient]++;
    }

    for(int i = 0; i < ingredients; i++){
      cin >> ingredient;
      if(m.find(ingredient) != m.end()) frecuency++;
    }

    if(frecuency >= ingredients/2)
      printf("similar\n");
    else
      printf("dissimilar\n");

  }
  return 0;
}