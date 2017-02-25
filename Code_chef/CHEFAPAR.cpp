#include <iostream>

using namespace std;

int main()
{
  int T,months,ans, payment;
  bool debts;
  scanf("%d",&T);
  while(T--)
  {
    ans = 0; debts = false;
    scanf("%d",&months);
    for(int i = 0; i < months; i++)
    {
      scanf("%d",&payment);
      if(!payment) debts = true;
      ans += debts ? 1100 : 1000;
      if(payment) ans -= 1000;
    }
    printf("%d\n",ans);
  }
  return 0;
}