#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  long long n,sum,i,a,prev;
  bool err;

  cin>>t;

  while(t--)
    {
        err=false;
        sum=0;
        cin>>n>>a;
        prev=a;
        for(i=1; i<n; i++)
        {
            cin>>a;
            if(a==prev)
                err=false;
            else
            {
                if(err==true)
                    sum+=1;
                else
                    sum+=2;
                err=true;
            }
            prev=a;
        }
        cout<<sum<<endl;
    }

    return 0;
}