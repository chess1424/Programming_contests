
#include <iostream>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string dicionary[100];
    bool out[100];
    cin>>t;
    while(t--)
    {
        int n,k;
        memset(out,false,sizeof(out));
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>dicionary[i];
        for(int i=0; i<k; i++)
        {
            int l;
            cin>>l;
            for(int j=0; j<l; j++)
            {
                string str;
                cin>>str;
                for(int s = 0; s<n; s++)
                    if(str == dicionary[s])
                        out[s] = true;
            }
        }
        for(int i=0; i<n; i++)
            cout<< ((out[i] == 0) ? "NO " : "YES ");
        cout<<endl;
    }
    return 0;
}