#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int correct = 0;
    string str,str2;
    cin>>str;
    cin>>str2;

    for(int i = 0; i < str.size(); i++)
    {
      char c = str[i];
      char c2 = str2[i];
      if(c == c2) ++correct;
    }

    long long out = 0, money;


    for(int i = 0; i <= n; i++)
    {
      cin>>money;
      if(i <= correct) out = max(money,out);
    }

    if(correct == n)
      cout<<money<<'\n';
    else
      cout<<out<<'\n';
  }
  return 0;
}