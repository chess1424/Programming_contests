/* Copyright 2017 Carlos Roberto Martinez Ojeda <carlos.1424@@live.com.mx>
   Link: https://coj.uci.cu/24h/problem.xhtml?pid=1103 */

#include <iostream>
#define COINS 5
#define maxMoney 7489

using namespace std;

int coins[] = {1,5,10,25,50};
int dp[maxMoney+1][COINS];

int maxChange(int money)
{
  return dp[money][COINS-1];
}

void initDP()
{
  for(int i = 0; i < COINS; i++)
    dp[0][i] = 1;
  for(int row = 1; row <= maxMoney; row++)
    for(int col = 0; col < COINS; col++)
    {
      //Take coin
      int takeCoin = (row - coins[col] < 0) ? 0 : dp[row - coins[col]][col];
      //Don't take coin
      int dontTakeCoin = (col - 1 < 0) ? 0 : dp[row][col-1];

      dp[row][col] = takeCoin + dontTakeCoin;
    }
}

int main()
{
  int n;
  initDP();

  while(scanf("%d",&n) != EOF)
   printf("%d\n",maxChange(n));

  return 0;
}
