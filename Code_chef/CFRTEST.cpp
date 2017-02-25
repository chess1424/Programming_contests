#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long t,n,i,sum;
    int dia;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        vector<bool> dias(100,false);
        for(i=0; i<n; i++)
        {
            cin>>dia;
            if(!dias[dia])
            {
                dias[dia]=true; ++sum;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}