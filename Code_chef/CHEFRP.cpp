#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    long long N,A,i,sum,min;
    bool imposible;
    cin>>T;
    while(T--)
    {
        cin>>N;
        sum=0;
        imposible=false;
        cin>>min;
        if(min==1) imposible=true;
        for(i=0; i<N-1; i++)
        {
            cin>>A;
            if(A==1)
            {
                imposible=true;
            }
            if(!imposible)
            {
                if(A>min)
                    sum+=A;
                else
                {
                    sum+=min;
                    min=A;
                }

            }

        }
        if(imposible)
            cout<<-1<<endl;
        else
        {
            sum+=2;
            cout<<sum<<endl;
        }

    }
    return 0;
}