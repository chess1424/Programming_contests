/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@live.com.mx>
   Problem_statement: https://www.codechef.com/APRIL17/problems/DISHLIFE */
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

#define maxSize (int)1e5

using namespace std;

bool ingredients[maxSize + 1];

string solve(const int &N, const int &K)
{
  bool some = false;
  int islandIngredients, ingredient, count = 0;

  fill(ingredients, ingredients+K+1, 0);

  for(int i = 0; i < N; i++){
    scanf("%d",&islandIngredients);

    for(int j = 0; j < islandIngredients; j++){
      scanf("%d",&ingredient);

      if(!ingredients[ingredient]){
         ingredients[ingredient] = true;

         if(++count == K && i < N-1)
          some = true;
      }
    }
  }

  if(some) return "some";

  return (count == K) ? "all" : "sad";
}

int main()
{
  int t, N, K; scanf("%d",&t);

  while(t--){
    scanf("%d %d",&N, &K);
    cout << solve(N, K) << '\n';
  }
  return 0;
}