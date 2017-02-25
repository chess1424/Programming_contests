
#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    long long t,sum,res;
    string s;
    int n,i,x;

    cin>>t;
    while(t--)
    {
        cin>>s; sum=0; res=0;
        cin>>n;

        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='S') sum++;
            else sum+=2;
        }

        int teclas=12*n;

        for(i=1; i<teclas; i++)
        {
            x=i;
            while(x<=teclas && x+sum<=teclas)
            {
                res++;
                x+=sum;
            }
        }
        cout<<res<<endl;
    }


    return 0;
}