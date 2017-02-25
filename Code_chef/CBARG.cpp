#include <iostream>

using namespace std;

int main()
{
    long long t,n,m,out,currentMemory,file,change;
    cin>>t;
    while(t--)
    {
        cin>>n>>file;
        out=currentMemory=file;
        --n;
        while(n--)
        {
            cin>>file;
            change=file-currentMemory;
            if(change>=0)
                out+=change;
            currentMemory+=change;
        }
        cout<<out<<endl;
    }
    return 0;
}