#include <iostream>
#include <stdio.h>
using namespace std;

long long cuentaCeros(long long n)
{
    long long ans=0;
    while(n%10==0)
    {
        n/=10;
        ans++;
    }
    return ans;
}

int main()
{
    long long n,num,prev;
    cin>>n;
    while(n--)
    {
        cin>>num;
        if(num%10==0)
        {
            prev=cuentaCeros(num);
            while(cuentaCeros(num*4)>prev)
            {
                num*=4;
                prev=cuentaCeros(num);
            }
            cout<<num<<endl;
        }
        else if(num%10==5)
        {
            num*=4;
            prev=cuentaCeros(num);
            while(cuentaCeros(num*4)>prev)
            {
                num*=4;
                prev=cuentaCeros(num);
            }
            cout<<num<<endl;

        }
        else
        {
            cout<<num<<endl;
        }

    }
    return 0;
}