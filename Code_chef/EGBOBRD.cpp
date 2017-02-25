#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    long long n,k,a,i,ans,popen,sobra;
    cin>>t;
    while(t--)
    {
        ans=0;
        sobra=0;

        cin>>n>>k;
        for(i=0; i<n; i++)
        {
            cin>>a;

            if(sobra>=a)
            {
                sobra-=a;
                if(sobra>0)
                    sobra--;
                continue;
            }
            else{
                a-=sobra;
            }


            popen=a/k;
            if(popen>0)
            {
                ans+=popen;
                sobra=a%k;
                if(sobra>0)
                {
                    ans++;
                    sobra=k-sobra;
                }
            }
            else
            {
                ++ans;
                sobra=k-a;
            }
            if(sobra>0)
                sobra--;
        }
        cout<<ans<<endl;
    }
    return 0;
}