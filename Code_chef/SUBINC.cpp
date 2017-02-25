#include <iostream>
#include <stdio.h>

using namespace std;
int main(int argc, char const *argv[])
{
  int t;
  long long n,out,maxNum,num;

  scanf("%d",&t);
  while(t--)
  {
    out = 0;
    scanf("%lld",&n);
    scanf("%lld",&num);
    maxNum = num;
    long long counter = 0;
    for(long long i = 1; i < n; i++)
    {
      scanf("%lld",&num);

      if(num >= maxNum)
        counter++;
      else
      {
        out += (counter * (counter + 1)) / 2;
        counter = 0;
      }
      maxNum =  num;
    }
    out += (counter * (counter + 1)) / 2;
    out += n;
    printf("%lld\n",out);
  }
  return 0;
}