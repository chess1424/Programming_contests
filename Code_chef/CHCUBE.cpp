#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string color,front,back;
    string cube[4];
    bool ans;
    while(t--)
    {
        ans=false;
        cin>>front>>back;
        cin>>cube[0];
        cin>>cube[2];
        cin>>cube[1];
        cin>>cube[3];

        for(int i=0; i<3; i++)
            if(cube[i]==cube[i+1] && (cube[i]==front || cube[i] == back))
                ans=true;
        if(cube[3]==cube[0] && (cube[3]==front || cube[3] == back)) ans=true;

        if(!ans)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}